#include <iostream>
#include "foo.h"
#include "help.h"
#include <vector>
int main(){
    try{
        Matrix first = input();
        std::cout<<"Исходная матрица: "<<std::endl;
        output(first);
        int a = getCallback();
        bool (*action)(Matrix matrix, int x) = callback(a);
        Matrix second = filter(first, action);
        std::cout<<"Итоговая матрица: "<<std::endl;
        output(second);
    } catch(const std::exception &e) {
        std::cerr << e.what()<<std::endl;
        return 1;
    }
    return 0;
}