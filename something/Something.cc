#include "Something.h"
#include <boost/date_time.hpp>
#include <boost/filesystem.hpp>

int Something::fn() {
    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    std::cout << "Current System Time = " << timeLocal << std::endl;
    boost::filesystem::directory_iterator iterator(std::string("."));
    for(; iterator != boost::filesystem::directory_iterator(); ++iterator)
    {
        std::cout << (iterator->path().filename()) << std::endl;
    }

    boost::filesystem::path full_path( boost::filesystem::current_path() );
    std::cout << "Current path is : " << full_path << std::endl;
    return 5;
}