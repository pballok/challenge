#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

std::set<int> readSetFromStream(std::stringstream& stream) {
    std::set<int> values;
    int i;
    while(stream >> i) {
        values.insert(values.end(), i);
        if(stream.peek() == ',') {
            stream.ignore();
        }
        if(stream.peek() == ';') {
            stream.ignore();
            break;
        }
    }
    
    return values;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Bad argument: please provide input file name." << std::endl;
        return 1;
    }
    
    std::ifstream input(argv[1]);
    std::string   line = "";
    while(std::getline(input, line)) {
        if(line == "") continue;
        
        std::stringstream  linestream(line);
        std::set<int>  set1 = readSetFromStream(linestream);
        std::set<int>  set2 = readSetFromStream(linestream);
        
        std::vector<int>           intersection(set1.size());
        std::vector<int>::iterator it;
        it = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersection.begin());
        intersection.resize(it - intersection.begin());
        
        for(it = intersection.begin(); it != intersection.end(); ) {
            std::cout << *it;
            ++it;
            if(it != intersection.end()) std::cout << ",";
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}
