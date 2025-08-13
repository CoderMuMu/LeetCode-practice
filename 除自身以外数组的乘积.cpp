#include <bits/stdc++.h>
using namespace std;
/*
    考察前后缀的理解，一个数的除自身以外的数组的乘积为他的前缀乘积*后缀乘积
*/
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    vector<int> preMul(n,1),sufMul(n,1);
    preMul[0] = 1,sufMul[n - 1] = 1;
    for (int i = 1;i < n;i++) {
        preMul[i] = preMul[i - 1] * nums[i - 1];
    }
    for (int i = n - 2;i >= 0;i--){
        sufMul[i] = sufMul[i + 1] * nums[i + 1];
    }
    for (int i = 0;i < n;i++) {
        ans.push_back(preMul[i] * sufMul[i]);
    }
    return ans;
}
//空间复杂度O(1)做法,求出后缀后，边计算前缀边计算答案
vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    ans[n - 1] = 1;
    for (int i = n - 2;i >= 0;i--) {
        ans[i] = ans[i + 1] * nums[i + 1];
    }
    int preMul = 1;
    for (int i = 0;i < n;i++) {
        //此时pre为nums[0]到nums[n - 1]的前缀乘积
        ans[i] *= preMul;
        preMul *= nums[i];
    }
    return ans;
}


int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf1(nums);
    for (int x:ans) {
        cout << x << " ";
    }
    return 0;
}
