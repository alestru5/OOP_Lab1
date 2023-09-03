
#include "foo.h"
#include "help.h"

bool filter_chet(Matrix matrix, int x){
    if (matrix.numbers[x] % 2 == 0){
        return true;
    }
    return false;
}

bool filter_unique(Matrix matrix, int x){
    int count = 0;
    for (int i = 0; i < matrix.count; i++){
        if (matrix.numbers[i] == matrix.numbers[x]){
            count += 1;
        }
    }
    if (count == 1){
        return true;
    }
    return false;
}

bool find(Matrix matrix, int i, int j){
    for (int t = 0; t < matrix.count; t++){
        if (matrix.cols[t] == i && matrix.rows[t] == j){
            return true;
        }
    }
    return false;
}

bool filter_ostrov(Matrix matrix, int x){
    for (int i = matrix.cols[x]-1; i < matrix.cols[x] + 2; i++){
        if (find(matrix, i, matrix.rows[x] - 1) || find(matrix, i, matrix.rows[x] + 1)){
            return false;
        }
        if (i != matrix.cols[x] && find(matrix, i, matrix.rows[x])){
            return false;
        }
        
    }
    return true;
}

bool (*callback(int a))(Matrix matrix, int x){
    if (a == 1){
        return filter_chet;
    } else if (a == 2){
        return filter_unique;
    } else {
        return filter_ostrov;
    }
}

Matrix input(){
    Matrix matrix;
    std::cout<<"Введите m и n:"<<std::endl;
    matrix.m = getInt();
    matrix.n = getInt();
    matrix.count = 0;
    std::cout<<"Введите матрицу"<<std::endl;
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

Matrix filter(Matrix matrix,  bool (*action)(Matrix matrix, int x)){
    Matrix f_matrix;
    f_matrix.m = matrix.m;
    f_matrix.n = matrix.n;
    f_matrix.count = 0;
    for (int i = 0; i < matrix.count; i++){
        if (action(matrix, i)){
            f_matrix.numbers.push_back(matrix.numbers[i]);
            f_matrix.cols.push_back(matrix.cols[i]);
            f_matrix.rows.push_back(matrix.rows[i]);
            f_matrix.count += 1;
        }
    }
    return f_matrix;
}

