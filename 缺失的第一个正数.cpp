#include <bits/stdc++.h>
using namespace std;
/*
    换座位思想：对于每个元素nums[i]都有nums[i] = i + 1,且1 <= nums[i] <= n
    如果他不在那么就交换到他应该在的位置，下标i = nums[i] - 1，直到在相应的位置即可
    最后遍历数组，看是否坐在了正确的位置。
*/
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0;i < n;i++) {
        while(1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            swap(nums[i],nums[j]);
        }
    }
    for (int i = 0;i < n;i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {

    vector<int> nums = {1,2,0};
    int ans = firstMissingPositive(nums);
    cout << ans << endl;

    return 0;
}
