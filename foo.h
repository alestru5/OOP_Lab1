#ifndef FOO_H
#define FOO_H
#include <iostream>
#include "help.h"
#include <vector>
struct Matrix{
    int m;
    int n;
    int count;
    int *numbers;
    std::pair<int, int> *coord;
};

bool filter_chet(Matrix &matrix, int a);
bool filter_unique(Matrix &matrix, int x);
bool filter_ostrov(Matrix &matrix, int x);

bool find(Matrix &matrix, int i, int j);
bool(*callback(int a))(Matrix &matrix, int x);

Matrix input();
void output(Matrix &matrix);

Matrix filter(Matrix &matrix, bool (*action)(Matrix &matrix, int x));


#endif