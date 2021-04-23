#pragma once

#include <string>

#include "pugixml.hpp"
#include "entities.hpp"

class Dataset {
public:
	explicit Dataset(const std::string& path);

	class Iterator {
		public:
			explicit Iterator() = default;
			explicit Iterator(pugi::xml_node stop);
			
			TransportStop operator*();
			bool operator!=(const Iterator& other);
			void operator++();

		private:
			pugi::xml_node curr_stop;
	};

	Iterator begin() const;
    Iterator end() const;

private:
	pugi::xml_document doc;
};

