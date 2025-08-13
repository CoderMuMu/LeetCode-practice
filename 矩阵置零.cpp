#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    unordered_map<int,int> mph,mpl;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (matrix[i][j] == 0) {
                mph[i]++;
                mpl[j]++;
            }
        }
    }
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (mph[i] > 0 || mpl[j] > 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {

    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for (auto x:matrix) {
        for (auto y:x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
