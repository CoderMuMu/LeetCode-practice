#include <bits/stdc++.h>
using namespace std;
/*
    考察动态规划，定义dp[i]为以nums[i]为结尾的最大子数组和
    分类讨论，如果nums[i]单独为一个数组，那么dp[i] = nums[i]
    如果与前面的拼起来，就是dp[i] = max(dp[i],dp[i - 1] + nums[i])
*/
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1);
    for (int i = 0;i < n;i++) dp[i] = nums[i];
    int ans = nums[0];
    for (int i = 1;i < n;i++) {
        dp[i] = max(dp[i - 1] + nums[i],dp[i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}
int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    cout << ans;

    return 0;
}
