#include <bits/stdc++.h>
using namespace std;
/*
    考察方向数组的使用，以及螺旋的规则。
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    vector<int> ans;
    int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
    int d = 0,i = 0,j = 0;
    for (int k = 0;k < m * n;k++) {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = 101;
        //尝试修改下标-尝试思想
        int x = i + dx[d],y = j + dy[d];
        //方向顺时针改变的两种情况，越界和下一元素为重复元素
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 101) {
            d = (d + 1) % 4; 
        }
        //正确的d，正确的下一坐标
        i = i + dx[d],j = j + dy[d];
    }
    return ans;
}

int main() {

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for (auto x:ans) {
        cout << x << " ";
    }

    return 0;
}
