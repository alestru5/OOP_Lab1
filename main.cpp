#include <iostream>
#include "foo.h"
#include "help.h"
#include <vector>
int main(){
    try{
        int m = getInt();
        int n = getInt();
        std::vector<int> numbers;
        std::vector<int> cols;
        std::vector<int> rows;
        int count = input(m, n, numbers, cols, rows);
        std::cout<<std::endl;
        output(count, m, n, numbers, cols, rows);
    } catch(...){
        std::cout<<"Error"<<std::endl;
    }
    return 0;
}