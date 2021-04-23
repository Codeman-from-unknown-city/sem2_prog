#pragma once

#include <string>
#include <vector>

struct TransportStop {
	std::string street;
	std::string type_of_vehicle;
	std::vector<std::string> routes;
	std::pair<double, double> coord;
};

