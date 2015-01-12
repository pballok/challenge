#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Missing input file name." << std::endl;
        return 1;
    }
    
    std::ifstream input(argv[1]);
    if(!input.good()) {
        std::cerr << "Failed to read from file: " << argv[1] << std::endl;
        return 1;
    }
    
    std::string  line = "";
    while(std::getline(input, line)) {
        std::istringstream linestream(line);
        if(line == "") continue;
        int x = 0;
        int n = 0;
        linestream >> x;
        linestream.ignore();
        linestream >> n;

        int multiple = 0;
        for(multiple = n; multiple < x; multiple += n) ;
        std::cout << multiple << std::endl;
    }
}
