#include <bits/stdc++.h>
using namespace std;
/*
    考察排除法，利用数组有序的性质，快速向target元素靠近
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int i = 0,j = n - 1;
    while (i < m && 0 <= j && j < n) {
        if (matrix[i][j] < target) {
            i++;
        }else if (matrix[i][j] > target){
            j--;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout << searchMatrix(matrix,target);
    return 0;
}
