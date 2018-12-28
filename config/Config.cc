#include <boost/property_tree/json_parser.hpp>

#include "Config.h"

Config::Config(const std::string filePath) {
    pt::read_json(filePath, _root);
}

Config::Config(std::istringstream& configStr) {
    pt::read_json(configStr, _root);
}

PropertyTree& Config::getCompound(const std::string& path) {
    return _root.get_child(path);
}