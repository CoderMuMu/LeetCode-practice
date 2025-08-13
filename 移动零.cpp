#include <bits/stdc++.h>
using namespace std;
/*
    index作为非0数字的下标，或者说是答案的下标
*/
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    for (int i = 0;i < n;i++) {
        if (nums[i] == 0) {
            continue;
        }
        nums[index++] = nums[i];
    }   
    for (int i = index;i < n;i++) {
        nums[i] = 0;
    }     
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for (int x:nums) {
        cout << x << " ";
    }
    return 0;
}
