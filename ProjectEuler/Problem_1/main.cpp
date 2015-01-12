#include <iostream>
#include <string>

unsigned long mySolution(long limit) {
    unsigned long solution = 0;

    int three_counter = 1;
    int five_counter = 1;
    for(long i = 1; i < limit; ++i, ++three_counter, ++five_counter) {
        three_counter %= 3;
        five_counter %= 5;

        if(three_counter == 0 || five_counter == 0) solution += i;
    }

    return solution;
}

unsigned long sumDivisibleBy(long limit, int n) {
    unsigned long p = limit / n;
    return n * (p * (p + 1)) / 2;
}

unsigned long officialSolution(long limit) {
    return sumDivisibleBy(limit, 3) + sumDivisibleBy(limit, 5) - sumDivisibleBy(limit, 15);
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <maxnumber>" << std::endl;
        return 0;
    }

    std::cout << mySolution(std::stol(argv[1])) << std::endl;
    std::cout << officialSolution(std::stol(argv[1])) << std::endl;
}
