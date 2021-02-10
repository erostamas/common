#include <boost/property_tree/json_parser.hpp>

#include "Config.h"

Config::Config(const std::string filePath) {
    try {
        pt::read_json(filePath, _root);
    } catch (const std::exception& e) {
        LOG_ERROR << "[Config] Failed to parse config file: " << filePath << ", reason: '" << e.what() << "'";
    }
}

Config::Config(std::istringstream& configStr) {
    pt::read_json(configStr, _root);
}

PropertyTree& Config::getCompound(const std::string& path) {
    return _root.get_child(path);
}