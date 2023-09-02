#include "help.h"

int getInt(){
    int a;
    while (true){
        std::cin>>a;
        if (std::cin.eof()){
            throw std::runtime_error("Failed to read number: EOF.");
        } else if (std::cin.bad()){
            throw std::runtime_error("Failed to read number.");
        } else if(std::cin.fail() || !std::cin.good()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Error, repeat, please!"<<std::endl;
        } else if (a >= std::numeric_limits<int>::min() && 
                    a<= std::numeric_limits<int>::max()){
            return a;
        }
    }
}