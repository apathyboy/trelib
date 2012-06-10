// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#ifndef TRELIB_CONFIG_READER_H_
#define TRELIB_CONFIG_READER_H_

#include <string>
#include <istream>
#include <vector>

namespace treLib {

    class ConfigReader
    {
    public:
        explicit ConfigReader(std::string filename);

        const std::vector<std::string>& GetTreFilenames();

    public:
        void ParseConfig();

        /**
         * Safe getline that handles endline's properly cross platform.
         * 
         * @param input
         * @param output
         * @return
         */
        std::istream& Getline(std::istream& input, std::string& output);

        std::vector<std::string> tre_filenames_;
        std::string config_filename_;
    };

}

#endif  // TRELIB_CONFIG_READER_H_
