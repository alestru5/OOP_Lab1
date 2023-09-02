
#include "foo.h"
int input(int m, int n, std::vector<int> &numbers, std::vector<int> &cols, std::vector<int> &rows){
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int x = getInt();
            if (x != 0){
                numbers.push_back(x);
                cols.push_back(j);
                rows.push_back(i);
                count += 1;
            }
        }
    }
    std::cout<<std::endl;
    return count;
}
void output(int count, int m, int n, std::vector<int> &numbers, std::vector<int> &cols, std::vector<int> &rows){
    int t = 0;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (t < count && cols[t] == j && rows[t] == i){
                std::cout<<numbers[t]<<" ";
                t += 1;
            } else{
                std::cout<<"0 ";
            }
        }
        std::cout<<std::endl;
    }
}