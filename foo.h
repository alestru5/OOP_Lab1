#ifndef FOO_H
#define FOO_H
#include <iostream>
#include "help.h"
#include <vector>
struct Matrix{
    int m;
    int n;
    int count;
    std::vector<int> numbers;
    std::vector<int> cols;
    std::vector<int> rows;
};

int filter_chet(int a);
int(*callback(int a))(int x);
Matrix input();
void output(Matrix matrix);
Matrix filter(Matrix matrix, int (*action)(int x));


#endif