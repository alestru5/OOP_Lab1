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

int getCallback(){
    int a;
    std::cout<<"Выберите фильтр:"<<std::endl;
    std::string msg[3]{"Четные числа", "Уникальные числа", "Одинокие числа числа"};
    for (int i = 0; i < sizeof(msg) / sizeof(msg[0]); i++){
        std::cout<<i + 1<<". "<<msg[i]<<std::endl;
    }
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
        } else if (a >= 1 && a<= sizeof(msg) / sizeof(msg[0])){
            return a;
        } else{
            std::cout<<"Error, repeat, please!"<<std::endl;
        }
    }
}