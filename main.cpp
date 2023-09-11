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
    } catch(const std::bad_alloc &ba){
        std::cerr<<"Not enough memory"<<std::endl;
        return 1;    
    } catch(const std::exception &e) {
        std::cerr << e.what()<<std::endl;
        return 1;
    }
    return 0;
}