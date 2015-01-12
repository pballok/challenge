#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Bad argument: please provide input file name." << std::endl;
        return 1;
    }
    
    std::ifstream infile(argv[1]);
    if(!infile.good()) {
        std::cerr << "Failed to read from file: " << argv[1] << std::endl;
    }
    
    int n;
    infile.setf(std::ios::hex, std::ios::basefield);
    while(infile >> n) {
        std::cout << n << std::endl;
    }
}

