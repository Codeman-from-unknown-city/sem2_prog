#include <iostream>
#include <vector>
#include <string>

#include "constants.hpp"
#include "dataset.hpp"
#include "analyst.hpp"

std::vector<std::string> types_of_vehicles = {
	"Трамвай",
	"Троллейбус",
	"Автобус",
};

int main() {
    Dataset dataset(PATH_TO_DATASET);
	Analyst analyst;
    for (const TransportStop& stop: dataset) 
		analyst.handle_stop(stop);
	std::cout << "The street with max number of stops:" << std::endl;
	std::cout << analyst.max_street.name << std::endl;;
	std::cout << "Routes with max number of stops:" << std::endl;
	for (auto& type_of_transport: types_of_vehicles) {
		std::cout << type_of_transport << ": ";
		std::cout << analyst.max_routes_by_stops[type_of_transport].name;
		std::cout << std::endl;
	}
	std::cout << "Routes with max dists:" << std::endl;
	for (auto& type_of_transport: types_of_vehicles) {
		std::cout << type_of_transport << ": ";
		std::cout << analyst.max_routes_by_dist[type_of_transport].name; 
		std::cout << std::endl;
	}
    return 0;
}

