#include "Configuration.h"
#include <vector>
#include <iostream>

Configuration::Configuration(char *path, char **system_env) {
    this->file.open(path);
    /*if (!file.is_open())
        exception;
    if (file.peek() == EOF)
        exception; */
    env = system_env;
}

Configuration::~Configuration() {
}
std::string Configuration::get_token(std::string &line){
    std::string token;
    int i = 0;
    if (line.empty()) {
        getline(this->file, line);
        return ("");
    }
    while (isspace(line[i]))
        i++;
    if (line[i] == '{' || line[i] == '}') {
        token += line[i];
        i++;
    }
    while (line[i] == '_' || line[i] == ':' || line[i] == '/' || line[i] == '\\' || line[i] == '.' || line[i] == '-' || isalnum(line[i])) {
        token += line[i];
        i++;
    }
    token[i] = '\0';
    line = line.substr(i, line.length() - i);
    return (token);
}
std::vector<Server> Configuration::parse() {

    std::string line, tmp, tmp2;
    std::vector<Server> servers;
    getline(this->file, line); //need to do thingies for empty lines
    while (get_token(line) == "server"){
        get_token(line);
        if (get_token(line) != "{")
            std::cout << "error" << std::endl;
        Server current_server;
        get_token(line);
        tmp = get_token(line);

        while (tmp != "}"){
            std::cout << "el MAIN token es :" << tmp << std::endl;
            if (tmp == "listen"){
                tmp = get_token(line);
                if (tmp.empty())
                    std::cout << "error" << std::endl;
                if (stoi(tmp) >= 0 && stoi(tmp) <= 65536) //maybe try
                    current_server.setPort(stoi(tmp));
                else
                    std::cout << "error" << std::endl;
                get_token(line);
            }

            if (tmp == "client_max_body_size"){
                tmp = get_token(line);
                if (tmp.empty())
                    std::cout << "error" << std::endl;
                if (stoi(tmp) >= 0 && stoi(tmp) <= 1024) //maybe try and say size to large si es necesario
                    current_server.setClientMaxBodySize(stoi(tmp));
                else
                    std::cout << "error" << std::endl;
                get_token(line);
            }

            if (tmp == "server_name"){
                tmp = get_token(line);
                if (tmp.empty())
                    std::cout << "error" << std::endl;
                std::vector<std::string> server_names;
                server_names.push_back(tmp);
                while (!tmp.empty()){
                    tmp = get_token(line);
                    server_names.push_back(tmp);
                }
                current_server.setServerNames(server_names);
            }

            if (tmp == "cgi") { //MOVE TO LOCATION
                tmp = get_token(line);
                tmp2 = get_token(line);
                if (tmp.empty() || tmp2.empty() || tmp2[0] != '.')
                    std::cout << "error" << std::endl;
                std::pair<std::string, std::string> cgi(tmp, tmp2);
                current_server.setCgi(cgi);
                get_token(line);
            }

            if (tmp == "error_page"){
                tmp = get_token(line);
                tmp2 = get_token(line);
                if (tmp.empty() || tmp2.empty())
                    std::cout << "error" << std::endl;
                std::map<int, std::string> error_page;
                while (!tmp.empty() && !tmp2.empty()){
                    error_page[stoi(tmp)] = tmp2;
                    tmp = get_token(line);
                    if (!tmp.empty())
                        tmp2 = get_token(line);
                }
                current_server.setErrorPage(error_page);
            }

            else{} // add error here
            tmp = get_token(line);
            //add more stuff, probably change blocks depending on if they can be in the location block
        }
        if (current_server.getPort() == -1)
            std::cout << "port was not setup" << std::endl; //add error and exit
        servers.push_back(current_server);
        get_token(line);
    }
    return (servers);
}
