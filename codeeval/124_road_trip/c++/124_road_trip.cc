#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Bad argument: please provide input file name." << std::endl;
        return 1;
    }
    
    std::ifstream infile(argv[1]);
    if(!infile.good()) {
        std::cerr << "Failed to read from file: " << argv[1] << std::endl;
    }
    
    std::string trip;
    while(std::getline(infile, trip)) {
        std::vector<unsigned int> distances;

        std::istringstream iss_trip(trip);
        std::string city;
        while(std::getline(iss_trip, city, ';')) {
            std::istringstream iss_city(city);

            std::string city_name;
            std::getline(iss_city, city_name, ',');
            
            unsigned int city_dist;
            iss_city >> city_dist;
            
            distances.push_back(city_dist);
        }
        
        std::sort(distances.begin(), distances.end());
        
        unsigned int total = 0;
        bool         first = true;
        for(auto d : distances) {
            if(first) first = false;
            else std::cout << ",";
            std::cout << d - total;
            total = d;
        }
        std::cout << std::endl;
    }
}

