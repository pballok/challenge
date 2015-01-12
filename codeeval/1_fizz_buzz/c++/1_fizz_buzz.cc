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
    
    int fizz = 0;
    int buzz = 0;
    int n    = 0;
    while(infile >> fizz >> buzz >> n) {
        for(int i = 1; i <= n; ++i) {
            bool print_fizz = (i % fizz == 0);
            bool print_buzz = (i % buzz == 0);
            
            if(print_fizz && print_buzz) {
                std::cout << "FB";
            }
            else {
                if(print_fizz) {
                    std::cout << "F";
                } else {
                    if(print_buzz) {
                        std::cout << "B";
                    } else {
                        std::cout << i;
                    }
                }    
            }
            
            if(i < n) std::cout << " ";
        }
        
        std::cout << std::endl;
    }
}
