
#ifndef WEBSERVER_SERVER_H
#define WEBSERVER_SERVER_H
#include <iostream>
#include <vector>
#include <map>
class Server {
public:
    Server();

    static void init_server(std::vector<Server> inst);

    const int &getPort() const;

    void setPort(const int &port);

    const std::vector<std::string> &getServerNames() const;

    void setServerNames(const std::vector<std::string> &serverNames);

    const std::pair<std::string, std::string> &getCgi() const;

    void setCgi(const std::pair<std::string, std::string> &cgi);

    const std::map<int, std::string> &getErrorPage() const;

    void setErrorPage(const std::map<int, std::string> &errorPage);

    int getClientMaxBodySize() const;

    void setClientMaxBodySize(int clientMaxBodySize);

private:
    int port;
    std::vector<std::string> server_names;
    std::pair<std::string, std::string> cgi; //move to location
    std::map<int, std::string> error_page; //if not setup, just go to a default 404.html
    int client_max_body_size; //if not defined, defaults to one, mb

};


#endif //WEBSERVER_SERVER_H
