#include <bits/stdc++.h>
using namespace std;
/*
    考察滑动窗口以及双端队列的使用，想象在飞机上看到连绵的群山，
    在飞机前进方向上，你想知道视野范围内最高的山，应当如何做？
    在视野范围内，如果新看到的山比已知的山要高，那么较矮的山不会是我们
    考虑范围内的山，所以直接去掉，其次，如果已知的山在视野范围外，也不是我们要考虑的山
    通过以上的举例可以知道，我们需要一个能从前后出，后面进的数据结构，这里可以使用双端队列
    双端队列适应于快速获得窗口内最大最小值。
    做法：保证单调性，保证窗口左端点的有效性
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0;i < n;i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {//保证单调性
            dq.pop_back();
        }
        dq.push_back(i);
        int left = i - k + 1;//此时窗口的大小，一开始错误的定义:dq.size()-k+1
        if(left < 0) {//确保窗口大小为k
            continue;
        }
        while(!dq.empty() && dq.front() < left) {//保证窗口左端点的有效性
            dq.pop_front();
        }
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for (int x:ans) {
        cout << x << ",";
    }

    return 0;
}
