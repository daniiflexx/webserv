
#ifndef WEBSERVER_CONFIGURATION_H
#define WEBSERVER_CONFIGURATION_H


#include <fstream>
#include "Server.h"
#include <map>
class Configuration {
public:
    Configuration(char *path, char **system_env);
    virtual ~Configuration();

    std::vector<Server> parse();
    std::string get_token(std::string &line);

private:
    char **env;
    std::ifstream file;

};


#endif //WEBSERVER_CONFIGURATION_H
