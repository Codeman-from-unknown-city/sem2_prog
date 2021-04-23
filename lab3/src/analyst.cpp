#include <cmath>

#include "analyst.hpp"

Analyst::Analyst() {
	max_street.n_of_stops = 0;
}

void Analyst::handle_stop(const TransportStop& stop) {
	handle_street_data(stop.street);
	for (auto& route: stop.routes)
		handle_route_data(stop.type_of_vehicle, route, stop.coord);
}

void Analyst::handle_street_data(const std::string& name) {
	if (name.size() == 0) 
		return;
	streets_count[name]++;
	if (streets_count[name] > max_street.n_of_stops) {
		max_street.name = name;
		max_street.n_of_stops = streets_count[name];
	}
}

using coord = std::pair<double, double>;

static inline double sqr(double num) {
	return pow(num, 2);
}

static double dist(const coord& c1, const coord& c2) {
	double dx = c1.first - c2.first;
	double dy = c2.second- c2.second;
	return sqrt(sqr(dx) + sqr(dy));
}

void Analyst::handle_route_data(const std::string& type_of_vehicle,
					   			const std::string& route_name,
					   			const std::pair<double, double>& coord) {
	RouteInfo& route = routes_info[type_of_vehicle + route_name];
	route.n_of_stops++;
	RouteWithStops& max_route_by_stops = max_routes_by_stops[type_of_vehicle];
	if (max_route_by_stops.n_of_stops < route.n_of_stops) {
		max_route_by_stops.name = route_name;
		max_route_by_stops.n_of_stops = route.n_of_stops;
	}
	route.dist += dist(route.last_stop_coord, coord);
	route.last_stop_coord = coord;
	RouteWithDist& max_route_by_dist = max_routes_by_dist[type_of_vehicle];
	if (max_route_by_dist.dist < route.dist) {
		max_route_by_dist.name = route_name;
		max_route_by_dist.dist = route.dist;
	}
}

