#include <bits/stdc++.h>
using namespace std;
/*
    考察双指针，通过前后缀分解的方式解答。当前位置能接多少水，取决于前面最高和后面最高
    所以通过前后缀双指针进行分解，获取前缀最大，后缀最大。
*/
int trap(vector<int>& height) {
    int n = height.size();
    int preMax = 0,sufMax = 0;
    int left = 0,right = n - 1;
    int ans = 0;
    while (left <= right) {
        preMax = max(height[left],preMax);
        sufMax = max(height[right],sufMax);
        if (preMax < sufMax) {
            ans += preMax - height[left++];
        }else{
            ans += sufMax - height[right--];
        }
    }
    return ans;
}
int main() {
    vector<int> height = {4,2,0,3,2,5};
    int ans = trap(height);
    cout << ans;
    return 0;
}
