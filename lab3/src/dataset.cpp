#include <vector>
#include <iostream>

#include "dataset.hpp"

static std::vector<std::string> parse_raw_routes(const std::string& raw_routes) {
	std::vector<std::string> routes;
	std::string tmp;
	for (char ch: raw_routes) 
		if (ch == '.' || ch == ',') {
			routes.push_back(tmp);
			tmp.clear();
		} else {
			tmp += ch;
		}
	routes.push_back(tmp);
	if (routes.empty())
		throw std::runtime_error("Trasport stops should contains numbers of routes");
	return routes;
}

static TransportStop map_xml_stop(const pugi::xml_node& xml_stop) {
	TransportStop stop;
	stop.type_of_vehicle = xml_stop.child_value("type_of_vehicle");
	stop.street = xml_stop.child_value("the_official_name");
	sscanf(xml_stop.child_value("coordinates"), "%lf,%lf", &stop.coord.first, 
		   												   &stop.coord.second);
	stop.routes = parse_raw_routes(xml_stop.child_value("routes"));
	return stop;
}

Dataset::Dataset(const std::string& path) {
	pugi::xml_parse_result parse_result = doc.load_file(path.c_str());
    if (!parse_result)
        throw std::invalid_argument(
        	"File " + path + " is invalid\n"
        	"Error description: " + parse_result.description() + "\n"
        ); 
}

Dataset::Iterator Dataset::begin() const {
	return Iterator(doc.first_child().first_child());
}

Dataset::Iterator Dataset::end() const {
	return Iterator();
}

Dataset::Iterator::Iterator(pugi::xml_node stop): curr_stop(stop)
{}

TransportStop Dataset::Iterator::operator*() {
	return map_xml_stop(curr_stop);
}

bool Dataset::Iterator::operator!=(const Iterator& other) {
	return curr_stop;
}

void Dataset::Iterator::operator++() {
	curr_stop = curr_stop.next_sibling();
}
