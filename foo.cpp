
#include "foo.h"
#include "help.h"

bool filter_chet(Matrix &matrix, int x){
    if (matrix.numbers[x] % 2 == 0){
        return true;
    }
    return false;
}

bool filter_unique(Matrix &matrix, int x){
    int count = 0;
    for (size_t i = 0; i < matrix.numbers.size(); i++){
        if (matrix.numbers[i] == matrix.numbers[x]){
            count += 1;
        }
    }
    if (count == 1){
        return true;
    }
    return false;
}

bool find(Matrix &matrix, int i, int j){
    for (size_t t = 0; t < matrix.numbers.size(); t++){
        if (matrix.coord[t].first == i && matrix.coord[t].second == j){
            return true;
        }
    }
    return false;
}

bool filter_ostrov(Matrix &matrix, int x){
    for (int i = matrix.coord[x].first-1; i < matrix.coord[x].first + 2; i++){
        if (find(matrix, i, matrix.coord[x].second - 1) || find(matrix, i, matrix.coord[x].second + 1)){
            return false;
        }
        if (i != matrix.coord[x].first && find(matrix, i, matrix.coord[x].second)){
            return false;
        }
        
    }
    return true;
}

bool (*callback(int a))(Matrix &matrix, int x){
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
    try{
        std::cout<<"Enter m и n:"<<std::endl;
        matrix.m = getNum<int>(0);
        matrix.n = getNum<int>(0);
        std::cout<<"Enter count not-zero numbers:"<<std::endl;
        matrix.count = getNum<int>(0);
        matrix.numbers = new int[matrix.count];
        matrix.coord = new std::pair<int, int>[matrix.count];
        for (int i = 0; i < matrix.count; i++){
            std::cout<<"Enter " <<i + 1<<" element: ";
            int t = getNum<int>();
            while (t == 0){
                std::cout<<"Not 0, pls. Repeat: " <<std::endl;
                t = getNum<int>();
            }
            std::cout<<"Enter i and j " <<i + 1<<" element: ";
            int x = getNum<int>(0, matrix.m - 1);
            int y = getNum<int>(0, matrix.n - 1);
            matrix.numbers[i] = t;
            matrix.coord[i] = std::make_pair(x, y);
        }    
    } catch(...){
        throw; 
    }    
    std::cout<<std::endl;
    return matrix;
}

void output(Matrix &matrix){
    size_t t = 0;
    for (int i = 0; i < matrix.m; i++){
        for (int j = 0; j < matrix.n; j++){
            if (t < matrix.numbers.size() && matrix.coord[t].first == i && matrix.coord[t].second == j){
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

Matrix filter(Matrix &matrix,  bool (*action)(Matrix &matrix, int x)){
    Matrix f_matrix;
    f_matrix.m = matrix.m;
    f_matrix.n = matrix.n;
    for (size_t i = 0; i < matrix.numbers.size(); i++){
        if (action(matrix, i)){
            f_matrix.numbers.push_back(matrix.numbers[i]);
            f_matrix.coord.push_back(std::make_pair(matrix.coord[i].first, matrix.coord[i].second));
        }
    }
    return f_matrix;
}

