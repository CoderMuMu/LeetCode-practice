#include <bits/stdc++.h>
using namespace std;
/*
    是否能合并要看第一个区间的右端点是否大于等于第二个区间的左端点，也就是是否是相交的。
    因为需要知道哪一个是第一个要合并的区间，所以对数组按照左端点从小到大的顺序进行排序。
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    int n = intervals.size();
    for (int i = 1;i < n;i++) {
        if (ans.back()[1] >= intervals[i][0]) {
            int start = ans.back()[0],end = max(intervals[i][1],ans.back()[1]);
            ans.pop_back();
            ans.push_back({start,end});
        }else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}


int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for (auto x:ans) {
        cout << x[0] << "," << x[1] << " ";
    }

    return 0;
}
