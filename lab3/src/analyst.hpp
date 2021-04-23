#pragma once 

#include <vector>
#include <unordered_map>
#include <string>

#include "entities.hpp"

struct Street {
	std::string name;
	int n_of_stops;
};

struct Route {
	std::string name;
};

struct RouteWithStops: public Route {
	int n_of_stops;
};

struct RouteWithDist: public Route {
	double dist;
};

struct RouteInfo {
	std::pair<double, double> last_stop_coord;
	double dist;
	int n_of_stops;
};

class Analyst {
public:
	Analyst();

	void handle_stop(const TransportStop& stop);

	Street max_street;
	std::unordered_map<std::string, RouteWithStops> max_routes_by_stops;
	std::unordered_map<std::string, RouteWithDist> max_routes_by_dist;

private:
	void handle_street_data(const std::string& name);
	std::unordered_map<std::string, int> streets_count;

	void handle_route_data(const std::string& type_of_vehicle,
						   const std::string& route_name,
						   const std::pair<double, double>& coord);
	std::unordered_map<std::string, RouteInfo> routes_info;
};

