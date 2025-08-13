#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    ListNode *next;
    int val;
    ListNode (ListNode* next):next(next){};
    ListNode (ListNode* next,int val):next(next),val(val){};
};
ListNode* reverseList(ListNode* head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur) {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}
ListNode *createListNode(vector<int>& list){
    if (list.empty()) return nullptr;
    ListNode *head = new ListNode (nullptr,list[0]);
    ListNode *cur = head;
    for (int i = 1;i < list.size();i++) {
        cur->next = new ListNode(nullptr,list[i]);
        cur = cur->next;
    }
    return head;
}
int main() {

    vector<int> list = {1,2,3,4,5};
    ListNode *head = createListNode(list);
    ListNode *ans = reverseList(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
