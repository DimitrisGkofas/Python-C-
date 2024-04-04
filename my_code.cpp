// my_code.cpp
#include <iostream>

extern "C" {
    // Function prototype
    void greet(const char* name);

    // Exported function
    void greet(const char* name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}