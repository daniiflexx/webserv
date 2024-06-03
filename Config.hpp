// Config.hpp

#include <string>
#include <vector>
#include <map>


class Config {

private:
    struct Route {
        std::string path;
        std::vector<std::string> accepted_methods;
        std::string redirect;
        std::string root;
        bool directory_listing;
        std::string default_file;
        std::map<std::string, std::string> cgi_extensions;
        bool accept_file_upload;
        std::string upload_path;
    };

    struct Server {
        std::string host;
        int port;
        std::string server_name;
        std::string error_page;
        int client_body_size_limit;
        std::vector<Route> routes;
    };
    std::vector<Server> servers;
public:
    Config(const std::string& filename);
    void printRoute(const Route& route);
    void printServer(const Server& server);
    void printAll();
};