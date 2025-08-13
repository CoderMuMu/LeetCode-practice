#include <bits/stdc++.h>
using namespace std;
/*
    1 2 3           1 4 7           7 4 1   
    4 5 6   ->      2 5 8   ->      8 5 2 
    7 8 9   转置    3 6 9   行反转   9 6 3
*/
//一次旋转 = 转置 + 行反转
void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < i;j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (auto &x:matrix){
        reverse(x.begin(),x.end());
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for (auto x : matrix) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
