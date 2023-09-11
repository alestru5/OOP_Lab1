
#include "foo.h"
#include "help.h"

bool filter_chet(Matrix &matrix, int x){
    if (matrix.numbers[x].data % 2 == 0){
        return true;
    }
    return false;
}

bool filter_unique(Matrix &matrix, int x){
    int count = 0;
    for (int i = 0; i < matrix.count; i++){
        if (matrix.numbers[i].data == matrix.numbers[x].data){
            count += 1;
        }
    }
    if (count == 1){
        return true;
    }
    return false;
}

bool find(Matrix &matrix, int i, int j){
    for (int t = 0; t < matrix.count; t++){
        if (matrix.numbers[t].coord.first == i && matrix.numbers[t].coord.second == j){
            return true;
        }
    }
    return false;
}

bool filter_ostrov(Matrix &matrix, int x){
    for (int i = matrix.numbers[x].coord.first-1; i < matrix.numbers[x].coord.first + 2; i++){
        if (find(matrix, i, matrix.numbers[x].coord.second - 1) || find(matrix, i, matrix.numbers[x].coord.second + 1)){
            return false;
        }
        if (i != matrix.numbers[x].coord.first && find(matrix, i, matrix.numbers[x].coord.second)){
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

bool cmp(Element &a, Element &b){
    if (a.coord.first < b.coord.first) return true;
    if (a.coord.first > b.coord.first) return false;
    if (a.coord.second < b.coord.second) return true;
    if (a.coord.second > b.coord.second) return false;
    return a.data < b.data;
}

Matrix input(){
    Matrix matrix;
    try{
        std::cout<<"Enter m и n:"<<std::endl;
        matrix.m = getNum<int>(0);
        matrix.n = getNum<int>(0);
        std::cout<<"Enter count not-zero numbers:"<<std::endl;
        matrix.count = getNum<int>(0);
        matrix.numbers = new Element[matrix.count];
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
            while (find(matrix, x, y)){
                std::cout<<"Enter unique i and j element: ";
                x = getNum<int>(0, matrix.m - 1);
                y = getNum<int>(0, matrix.n - 1);
            }
            matrix.numbers[i].data = t;
            matrix.numbers[i].coord = std::make_pair(x, y);
        }
        std::sort(matrix.numbers, matrix.numbers + matrix.count, cmp);
    }catch(...){
        erase(matrix);
        throw; 
    }    
    std::cout<<std::endl;
    return matrix;
}

void output(Matrix &matrix){
    int t = 0;
    for (int i = 0; i < matrix.m; i++){
        for (int j = 0; j < matrix.n; j++){
            if (t < matrix.count && matrix.numbers[t].coord.first == i && matrix.numbers[t].coord.second == j){
                std::cout<<matrix.numbers[t].data<<" ";
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
    int t = 0;
    f_matrix.numbers = new Element[matrix.count];
    for (int i = 0; i < matrix.count; i++){
        if (action(matrix, i)){
            f_matrix.numbers[t] = matrix.numbers[i];
            t += 1;
        }
    }
    f_matrix.count = t;

    Element *tmp1 = new Element[t];
    std::copy(f_matrix.numbers, f_matrix.numbers + t, tmp1);
    delete [] f_matrix.numbers;
    f_matrix.numbers = tmp1;

    return f_matrix;
}

void erase(Matrix &matrix){
    delete [] matrix.numbers;
}

