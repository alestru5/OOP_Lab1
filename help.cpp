#include "help.h"

int getCallback(){
    std::cout<<"Enter filter:"<<std::endl;
    std::string msg[3]{"Even numbers", "Unique numbers", "Along numbers"};
    for (size_t i = 0; i < sizeof(msg) / sizeof(msg[0]); i++){
        std::cout<<i + 1<<". "<<msg[i]<<std::endl;
    }
    int a = getNum<int>(1, 3);
    return a;
}