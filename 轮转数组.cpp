#include <bits/stdc++.h>
using namespace std;
/*
    考察对轮转的理解以及对reverse函数的使用，向右轮转k次，就是将数组最后k个元素依次移到
    数组首位，正好可以使用反转整个数组，反转前k个元素，反转后n-k个元素
*/
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin() + k);
    reverse(nums.begin() + k,nums.end());
}

int main() {

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums,k);
    for (int x:nums) {
        cout << x << " ";
    }
    return 0;
}
