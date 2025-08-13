#include <bits/stdc++.h>
using namespace std;
/*
    考察滑动窗口，需要额外注意，substr会拷贝一份字符串，若字符串过长会导致内存溢出
    这里使用下标对应字符串起始位置和终止位置。
*/
bool isValid(vector<int> &mps,vector<int> &mpt) {
    for (char c = 'a';c <= 'z';c++){
        if (mps[c] < mpt[c]) {
            return false;
        }
    }
    for (char c = 'A';c <= 'Z';c++){
        if (mps[c] < mpt[c]) {
            return false;
        }
    }//遍历大小字母只用遍历52个，常数则遍历128个
    // for(int i = 0;i < 128;i++) {
    //     if(mpt[i] > 0 && mpt[i] > mps[i]) {
    //         return false;
    //     }
    // }
    // return true;
}
string minWindow(string s, string t) {
    int m = s.size(),n = t.size();
    if(m < n) return "";
    string ans = "";
    vector<int> mps(128,0),mpt(128,0);
    for (char c:t) {
        mpt[c]++;
    }
    int left = 0,ansLeft = -1,ansRight = m;
    for (int right = 0;right < m;right++) {
        char c = s[right];
        mps[c]++;
        //int left = right - n + 1;//不应该是固定长度,会错过正确答案
        // if(curLen < n) {
        //     continue;
        // }下面的合法性验证会涵盖窗口大小
        while(isValid(mps,mpt)){
            if(right - left < ansRight - ansLeft) {
                ansLeft = left;
                ansRight = right;
            }
            mps[s[left]]--;
            left++;
        }   
    }
    return ansLeft < 0 ? "" : s.substr(ansLeft,ansRight - ansLeft + 1);
}
int main() {

    string s = "ADOBECODEBANC",t = "ABC";
    string ans = minWindow(s,t);
    cout <<"ans = " << ans;

    return 0;
}
