#include "Logging.h"

#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <iomanip>
#include <unordered_map>

// LCOV_EXCL_START

BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)

namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
namespace src = boost::log::sources;

const std::unordered_map<std::string, severity_level> logLevels = {
	{"TRACE", severity_level::TRACE  },
    {"DEBUG", severity_level::DEBUG },
    {"INFO",  severity_level::INFO  },
    {"WARN",  severity_level::WARNING  },
	{"ERROR", severity_level::ERROR }
};

BOOST_LOG_GLOBAL_LOGGER_INIT(global_logger, src::logger) {
    logger_t _logger;
    return _logger;
}

void init_logging(const std::string& logFilePath, const std::string& logLevelStr, uint64_t rotationSize) {
    boost::log::add_common_attributes();
    boost::log::add_file_log(
			keywords::file_name = logFilePath,
            keywords::rotation_size = rotationSize,
            keywords::open_mode = (std::ios::out | std::ios::app),
            keywords::auto_flush = true,
            keywords::format = (
                expr::stream
                << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
                << " [" << expr::attr<severity_level>("Severity") << "]: "
                << expr::smessage));

    LOG_INFO << "log initialized with log level: " << logLevelStr << ", rotation size set to: " << rotationSize << " bytes";
    boost::log::core::get()->set_filter(severity >= logLevels.at(logLevelStr));
}

// for testing maybe
void init_logging(std::ostream& sink, const std::string& logLevelStr) {
    boost::log::add_common_attributes();
    boost::log::add_console_log(
			sink,
            keywords::auto_flush = true,
            keywords::format = (
                expr::stream
                << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
                << " [" << expr::attr<severity_level>("Severity") << "]: "
                << expr::smessage));

    LOG_INFO << "log initialized with log level: " << logLevelStr;
    boost::log::core::get()->set_filter(severity >= logLevels.at(logLevelStr));
}

std::ostream& operator<<(std::ostream& os, severity_level level) {
    if (static_cast<size_t>(level) < logLevels.size()) {
		for (const auto& l : logLevels) {
			if (l.second == level) {
				os << std::left << std::setw(5) << l.first;
				return os;
			}
		}
    } else {
        os << static_cast<int>(level);
    }

    return os;
}

// LCOV_EXCL_STOP
