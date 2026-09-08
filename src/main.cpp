#include <fstream>
#include <iostream>
#include <string>

#include "demo.hpp"

std::string greeting(const std::string& name) { return "Hello, " + name + "!"; }

int main(int argc, char* argv[]) {
    std::string input = (argc > 1) ? argv[1] : "world";
    std::cout << greeting(input) << "\n";

    // If a CSV path is passed (see `make run`), count lines as a sanity check.
    if (argc > 1) {
        std::ifstream f(argv[1]);
        if (!f) {
            std::cerr << "note: cannot open '" << argv[1] << "', skipping file demo\n";
            return 0;
        }
        size_t lines = 0;
        std::string line;
        while (std::getline(f, line)) {
            ++lines;
        }
        std::cout << "lines in " << argv[1] << ": " << lines << "\n";
    }
    return 0;
}
