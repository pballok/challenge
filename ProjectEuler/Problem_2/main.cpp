#include <iostream>
#include <string>

unsigned long mySolution(long limit) {
    unsigned long solution = 0;

    unsigned long i = 1;
    unsigned long j = 1;
    unsigned long k = 2;

    do {
        solution += k;
        i = j + k;
        j = k + i;
        k = i + j;
    } while(k < limit);

    return solution;
}

unsigned long officialSolution(long limit) {
    unsigned long i = 2;
    unsigned long j = 8;
    unsigned long k = 0;

    unsigned long solution = i + j;

    while((k = 4 * j + i) < limit) {
        solution += k;
        i = j;
        j = k;
    };

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
