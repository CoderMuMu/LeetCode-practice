#include <bits/stdc++.h>
using namespace std;
/*
    考察滑动窗口，滑动窗口固定套路，right向右移动增加窗口内的元素
    是导致子串重复的主要原因，left向右移动缩小窗口，减少重复的字符
    对应题目，保证窗口内的子串是唯一的。
*/
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char,int> mp;
    int left = 0,right = 0,ans = 0;
    while (right < n) {
        mp[s[right]]++;
        while(mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }
        ans = max(ans,right - left + 1);
        right++;
    }
    return ans;
}
int main() {
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}
