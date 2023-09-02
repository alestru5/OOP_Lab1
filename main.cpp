#include <iostream>
#include "foo.h"
#include "help.h"
#include <vector>
int main(){
    try{
        Matrix first = input();
        output(first);
        int (*action)(int x) = filter_chet;
        Matrix second = filter(first, action);
        output(second);
    } catch(...){
        std::cout<<"Error"<<std::endl;
    }
    return 0;
}