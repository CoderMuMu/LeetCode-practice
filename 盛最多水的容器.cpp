#include <bits/stdc++.h>
using namespace std;
/*
    考察双指针的移动，木桶原理，谁短移动谁
*/
int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0,right = n - 1,ans = 0;
    while (left < right) {
        int l = height[left],r = height[right];
        ans = max(min(l,r) * (right - left),ans);//right-left表示宽，而不是元素个数
        if (l < r) {
            left++;
        }else{
            right--;
        }
    }
    return ans;
}
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);
    return 0;
}
