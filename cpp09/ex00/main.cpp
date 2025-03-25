#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if(argc != 2){
        std::cerr << "Error: could not open file" << std::endl;
        return(1);
    }
    std::ifstream file(argv[0]);
    if (!file){
        std::cerr << "Error: could not open file" << std::endl;
        return(1);
    }
}
