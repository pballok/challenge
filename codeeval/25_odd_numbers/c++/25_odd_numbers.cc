#include <iostream>

const int MAX_NUMBER = 99;

int main(int, char**) {
    for(int i = 0; i < MAX_NUMBER; ++i) {
        std::cout << ++i << std::endl;
    }
}
