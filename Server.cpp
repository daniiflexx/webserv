#include "Server.h"
Server::Server() {
    this->port = -1;
    this->client_max_body_size = 1;
    //this->server_names = nullptr;
}

/*
std::string port;

std::vector<std::string> server_names;
std::pair<std::string, std::string> cgi;
std::vector<std::string> error_page;
*/




void Server::init_server(std::vector<Server> inst){

    for (size_t i = 0; i < inst.size(); i++){   //this is just a check to see if parse is okay
        std::cout << "The port is = " << inst[i].getPort() << std::endl;
    }
}
const int &Server::getPort() const {
    return port;
}

void Server::setPort(const int &port) {
    this->port = port;
}

const std::vector<std::string> &Server::getServerNames() const {
    return server_names;
}

void Server::setServerNames(const std::vector<std::string> &serverNames) {
    server_names = serverNames;
}

const std::pair<std::string, std::string> &Server::getCgi() const {
    return cgi;
}

void Server::setCgi(const std::pair<std::string, std::string> &cgi) {
    this->cgi = cgi;
}

const std::map<int, std::string> &Server::getErrorPage() const {
    return error_page;
}

void Server::setErrorPage(const std::map<int, std::string> &errorPage) {
    error_page = errorPage;
}

int Server::getClientMaxBodySize() const {
    return client_max_body_size;
}

void Server::setClientMaxBodySize(int clientMaxBodySize) {
    client_max_body_size = clientMaxBodySize;
}
