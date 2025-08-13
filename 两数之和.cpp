#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0;i < nums.size();i++) {
        int x = nums[i];
        if (mp.count(target - x)) {
            return {i,mp[target - x]};
        }
        mp[x] = i;
    }
    return {};
}
int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(nums,target);
    for (auto x:ans) {
        cout << x << ' ';
    }
 
    return 0;
}
