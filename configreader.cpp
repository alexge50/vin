#include "configreader.h"
#include "trim.h"

// TODO: Cross-platform method of specifying config location
std::string ConfigReader::CONFIG_FILE { "vinc.conf" };

ConfigReader::ConfigReader()
{
    
}

bool ConfigReader::load()
{
    std::ifstream config { CONFIG_FILE };
    
    std::string line;
    while (std::getline(config, line))
    {
        auto eq = line.find('=');
        if (eq != std::string::npos)
        {
            std::string opt = line.substr(0, eq);
            std::string val = line.substr(eq + 1);

            ErrorCode status = options.set_option(opt, val);
            if (status != ErrorCode::OK)
                error(status, opt, val);
        }
    }

    config.close();

    return true;
}

void ConfigReader::error(ErrorCode err, const std::string& opt, const std::string& val)
{
    // TODO: Cross platform method of notifying user of invalid option or value.
}
