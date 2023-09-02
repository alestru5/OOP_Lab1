#ifndef FOO_H
#define FOO_H
#include <iostream>
#include "help.h"
#include <vector>
int input(int m, int n, std::vector<int> &numbers, std::vector<int> &cols, std::vector<int> &rows);
void output(int count, int m, int n, std::vector<int> &numbers, std::vector<int> &cols, std::vector<int> &rows);

#endif