#include <iostream>
#include <string>
#include <set>
#include <vector>

// Find the largest prime factor of n

unsigned long mySolution(unsigned long n) {
    unsigned long solution = 0;
    unsigned long limit  = n;
    for(unsigned long i = 2; i <= limit; ++i) {
        if(limit % i == 0) {
            solution = i;
            limit /= i;
            --i;
        }
    }

    return solution;
}

unsigned long officialSolution(unsigned long n) {
    unsigned long solution = 0;

    return solution;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <maxnumber>" << std::endl;
        return 0;
    }

    std::cout << mySolution(std::stol(argv[1])) << std::endl;
    std::cout << officialSolution(std::stol(argv[1])) << std::endl;
}
