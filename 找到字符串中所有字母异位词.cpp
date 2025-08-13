#include <bits/stdc++.h>
using namespace std;
/*
    考察定长滑动窗口，右端点向右滑动，当窗口长度==p的长度时，判断是否是异位词
    注意窗口向右移动后，左端点对应的字符需要去掉。这里哈希表的相等是完全相等，
    即键相等，值也相等，所以使用哈希表判断是否是异位词的时候，若某个键对应的值为9
    那么需要erase掉。或者使用vector代替也可以。
*/
vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> cnt_p,cnt_s;
    for (char c:p) {
        cnt_p[c]++;
    }
    vector<int> ans;
    int k = p.size();
    for (int right = 0;right < s.size();right++) {
        char c = s[right];
        cnt_s[c]++;
        int left = right - k + 1;
        if(left < 0) {
            continue;
        }
        if(cnt_p == cnt_s) {
            ans.push_back(left);
        }
        cnt_s[s[left]]--;
        if(cnt_s[s[left]] == 0) {
            cnt_s.erase(s[left]);
        }
    }
    return ans;
}

int main() {
    string s = "cbaebabacd",p = "abc";
    vector<int> ans = findAnagrams(s,p);
    for (int x:ans) {
        cout << x << " ";
    }
    return 0;
}
