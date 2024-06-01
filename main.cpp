#include "Config.hpp"

int main() {
    Config myConfig = Config("file.conf");
    myConfig.printAll();
}