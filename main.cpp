#include "Config.hpp"
#include <iostream>
#include <fstream>
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
        return 1;
    }
    try {
        Config config(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    Config myConfig = Config("file.conf");
    myConfig.printAll();
}