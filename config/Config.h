#pragma once

#include <boost/property_tree/ptree.hpp>
#include <string>

#include "Logging.h"

namespace pt = boost::property_tree;
using PropertyTree = pt::ptree;

class Config {
public:
    Config(const std::string filePath);
    explicit Config(std::istringstream& configStr);

    template<class ValueType>
    ValueType get(const std::string& path, ValueType defaultValue) {
        ValueType value = _root.get(path, defaultValue);
        LOG_INFO << "[Config] " << path << " : " << value;
        return value;
    }
    PropertyTree& getCompound(const std::string& path);

private:
    PropertyTree _root;

};
