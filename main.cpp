#include <iostream>
#include "help.h"
#include "foo.h"

#include <vector>


int main(){
    Matrix first;
    Matrix second;
    try{
        first = input();
        std::cout<<"Your matrix: "<<std::endl;
        output(first);
        int a = getCallback();
        bool (*action)(Matrix &matrix, int x) = callback(a);
        second = filter(first, action);
        std::cout<<"Final matrix: "<<std::endl;
        output(second);
        erase(first);
        erase(second);
    } catch(const std::exception &e) {
        std::cerr << e.what()<<std::endl;
        erase(first);
        erase(second);
        return 1;
    }
    return 0;
}