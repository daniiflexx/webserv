// Config.cpp

#include "Config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Config::Config(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    Server* current_server = NULL;
    Route* current_route = NULL; 

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;

        if (word == "server") {
            servers.push_back(Server());
            current_server = &servers.back();
        } else if (word == "route") {
            current_server->routes.push_back(Route());
            current_route = &current_server->routes.back();
        }else if(word == "path") {
            iss >> current_route->path;
        } else if (word == "host") {
            iss >> current_server->host;
        } else if (word == "port") {
            iss >> current_server->port;
        } else if (word == "server_name") {
            iss >> current_server->server_name;
        } else if (word == "error_page") {
            iss >> current_server->error_page;
        } else if (word == "client_body_size_limit") {
            iss >> current_server->client_body_size_limit;
        } else if (word == "accepted_methods") {
            std::string method;
            while (iss >> method) {
                current_route->accepted_methods.push_back(method);
            }
        } else if (word == "redirect") {
            iss >> current_route->redirect;
        } else if (word == "root") {
            iss >> current_route->root;
        } else if (word == "directory_listing") {
            std::string on_off;
            iss >> on_off;
            current_route->directory_listing = (on_off == "on");
        } else if (word == "default_file") {
            iss >> current_route->default_file;
        } else if (word == "cgi_extensions") {
            std::string ext, path;
            while (iss >> ext >> path) {
                current_route->cgi_extensions[ext] = path;
            }
        } else if (word == "accept_file_upload") {
            std::string on_off;
            iss >> on_off;
            current_route->accept_file_upload = (on_off == "on");
        } else if (word == "upload_path") {
            iss >> current_route->upload_path;
        }
    }
}

void Config::printServer(const Server& server) {
    std::cout << "Server Information:" << std::endl;
    std::cout << "Host: " << server.host << std::endl;
    std::cout << "Port: " << server.port << std::endl;
    std::cout << "Server Name: " << server.server_name << std::endl;
    std::cout << "Error Page: " << server.error_page << std::endl;
    std::cout << "Client Body Size Limit: " << server.client_body_size_limit << std::endl;
    std::cout << std::endl;
}

void Config::printRoute(const Route& route) {
    std::cout << "Route Information:" << std::endl;
    std::cout << "Path: " << route.path << std::endl;
    std::cout << "Redirect: " << route.redirect << std::endl;
    std::cout << "Root: " << route.root << std::endl;
    std::cout << "Directory Listing: " << (route.directory_listing ? "on" : "off") << std::endl;
    std::cout << "Default File: " << route.default_file << std::endl;
    std::cout << "CGI Extensions: ";
    for (std::map<std::string, std::string>::const_iterator it = route.cgi_extensions.begin(); it != route.cgi_extensions.end(); ++it) {
        std::cout << it->first << " -> " << it->second << ", ";
    }
    std::cout << std::endl;
    std::cout << "Accept File Upload: " << (route.accept_file_upload ? "on" : "off") << std::endl;
    std::cout << "Upload Path: " << route.upload_path << std::endl;
}

void Config::printAll() {
    std::cout << "Printing all server information:" << std::endl;
    for (std::vector<Server>::const_iterator it = servers.begin(); it != servers.end(); ++it) {
        printServer(*it);
        std::cout << std::endl;
        for (std::vector<Route>::const_iterator rt = it->routes.begin(); rt != it->routes.end(); ++rt) {
            printRoute(*rt);
            std::cout << std::endl;
        }
    }
}
