#include <bits/stdc++.h>
using namespace std;
// 0 1 2 3 4
// 0 1 3 6 101
/*
    考察前缀和，题意：若一个连续非空序列[i,j]的和为k则是一个
    符合要求的子数组，即sj-si=k,等价于si=sj-k。联想到两数之和
    找前缀和数组中是否存在si=sj-k。
    前缀和定义：preSum[i]为前i个元素的和
    preSum[i] = preSum[i-1]+nums[i-1]
*/
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    vector<int> preSum(n + 1);
    for (int i = 0;i < n;i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    unordered_map<int,int> cnt;
    cnt[0] = 1;
    for (int sj:preSum) {
        if(cnt.count(sj - k)) {
            ans += cnt[sj - k];
        }
        cnt[sj]++;
    }
    return ans;
}
int main() {
    vector<int> nums = {1,2,3};
    int k = 3;
    int ans = subarraySum(nums,k);
    cout << ans;
    return 0;
}
