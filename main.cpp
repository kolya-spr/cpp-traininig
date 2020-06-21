#include <iostream>
#include "version.h"

int version() {
    return CI_BUILD_NUMBER;
}

int main() {
    std::cout << "build " << version() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
