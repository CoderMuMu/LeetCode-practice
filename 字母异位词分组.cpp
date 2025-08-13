#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
/*
    本题考查对哈希表的使用，所谓字母异位词就是排序后，单词是一样的，利用这个特点将排序后的字符串作为键，异位词作为值。
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;
    for (string s:strs) {
        string t = s;
        sort(t.begin(),t.end());
        mp[t].push_back(s);
    }
    for (auto it:mp) {
        ans.push_back(it.second);
    }
    return ans;
}
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto &x:ans) {
        for (auto &y:x) {
            cout << y << " ";
        }
        cout <<"//" << " ";
    }
    return 0;
}
