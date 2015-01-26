#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

int beautyValue(const std::string& line) {
    std::map<char, int> char_count;
    
    // Count each letter
    for(const char& c : line) {
        if(std::isalpha(c)) {
            char_count[std::tolower(c)]++;
        }
    }
    
    // Copy the amounts into a vector
    std::vector<int> char_count_list;
    for(auto c : char_count) {
        char_count_list.push_back(c.second);
    }
    
    std::sort(char_count_list.begin(), char_count_list.end(), std::greater<int>());
    
    int total_beauty = 0;
    int letter_beauty = 26;
    for(auto i : char_count_list) {
        total_beauty += i * letter_beauty--;
    }
    
    return total_beauty;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Bad argument: please provide input file name." << std::endl;
        return 1;
    }
    
    std::ifstream infile(argv[1]);
    if(!infile.good()) {
        std::cerr << "Failed to read from file: " << argv[1] << std::endl;
    }
    
    std::string line;
    while(std::getline(infile, line)) {
        if(line != "") std::cout << beautyValue(line) << std::endl;
    }
}
