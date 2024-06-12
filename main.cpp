#include <iostream>
#include "Configuration.h"
#include "Server.h"
int main(int argc, char **argv, char **env) {

    if (argc > 2)
        return (1); //this will be an exception
    char *path = (argc == 2) ? argv[1] : nullptr;
    Configuration conf(path, env);
    Server::init_server(conf.parse());
    std::cout << "done" << std::endl;
    return 0;
}
