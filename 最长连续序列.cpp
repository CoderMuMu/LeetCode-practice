#include <bits/stdc++.h>
using namespace std;
/*
    考察对哈希表/集合的理解，寻找最长连续序列，利用连续的特点，寻找下一个数字x-1
    如果不存在那么这个数就是他所在序列的第一个元素，以他为起点不断判断y=x,y+1是否存在
    y-1就是当前连续序列的终点，答案ans=y-1-x+1=y-x
    额外需要注意的是重复元素的问题
*/
int longestConsecutive1(vector<int>& nums) {
    unordered_map<int,int> mp;
    int ans = 0;
    //对于有多个相同元素的数组，使用哈希表会增大查询量，增大复杂度，所以使用哈希集合
    for (int x:nums) {
        mp[x];//需提前记录元素是否存在，否则会对x-1失去有效判断
    }
    for (int x:nums) {
        if (mp.count(x - 1)){
            continue;
        }
        int y = x;
        while (mp.count(y)) {
            y++;
        }
        ans = max(ans,y - x);
    }
    return ans;
}
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(),nums.end());
    int ans = 0;
    for(int x:st) {//对去重的集合遍历，数据量小
        if (st.count(x - 1)) {
            continue;
        }
        int y = x;
        while (st.count(y)){
            y++;
        }
        ans = max(ans,y - 1 - x + 1);
    }
    return ans;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    int ans = longestConsecutive(nums);
    cout << ans;
    return 0;
}
