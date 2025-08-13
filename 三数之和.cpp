#include <bits/stdc++.h>
using namespace std;
/*
    考察双指针，通过固定i，移动j，k来遍历数组，找出符合条件的三元组，
    将三数之和转换成两数之和 nums[i]+nums[j]+nums[k]==0变为nums[i]=-(nums[j]+nums[k])
    要注意的是三元组不能重复。传统的做法就是三层遍历，每层取一个数，时间复杂度O(n^3)，
    这里并没有用到排序，通过排序我们可以省去很多没有必要的遍历。
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int i = 0;i + 2 < nums.size();i++) {
        int x = nums[i];
        if(i - 1 >= 0 && x == nums[i - 1]) {//重复值
            continue;
        }
        int j = i + 1,k = nums.size() - 1;
        if(x + nums[k - 1] + nums[k] < 0) {//优化
            continue;
        }
        if(x + nums[j] + nums[i + 2] > 0) {//优化
            continue;
        }
        while (j < k) {
            int sum = x + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            }else if (sum > 0){
                k--;
            }else{
                ans.push_back({x,nums[j],nums[k]});
                //这里j和k先移动，避开已经添加的重复元素。
                j++;
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }  
                k--;
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto x:ans) {
        for (auto y:x) {
            cout << y <<',';
        }
        cout << '/' ;
    }


    return 0;
}
