
#include "foo.h"
#include "help.h"

int filter_chet(int x){
    if (x % 2 == 0){
        return 1;
    }
    return 0;
}

int (*callback(int a))(int x){
    if (a == 1){
        std::cout<<"asdf";
    }
    return filter_chet;
}

Matrix input(){
    Matrix matrix;
    matrix.m = getInt();
    matrix.n = getInt();
    matrix.count = 0;
    for (int i = 0; i < matrix.m; i++){
        for (int j = 0; j < matrix.n; j++){
            int x = getInt();
            if (x != 0){
                matrix.numbers.push_back(x);
                matrix.cols.push_back(j);
                matrix.rows.push_back(i);
                matrix.count += 1;
            }
        }
    }
    std::cout<<std::endl;
    return matrix;
}

void output(Matrix matrix){
    int t = 0;
    for (int i = 0; i < matrix.m; i++){
        for (int j = 0; j < matrix.n; j++){
            if (t < matrix.count && matrix.cols[t] == j && matrix.rows[t] == i){
                std::cout<<matrix.numbers[t]<<" ";
                t += 1;
            } else{
                std::cout<<"0 ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Matrix filter(Matrix matrix,  int (*action)(int x)){
    Matrix f_matrix;
    f_matrix.m = matrix.m;
    f_matrix.n = matrix.n;
    f_matrix.count = 0;
    for (int i = 0; i < matrix.count; i++){
        if (action(matrix.numbers[i])){
            f_matrix.numbers.push_back(matrix.numbers[i]);
            f_matrix.cols.push_back(matrix.cols[i]);
            f_matrix.rows.push_back(matrix.rows[i]);
            f_matrix.count += 1;
        }
    }
    return f_matrix;
}

