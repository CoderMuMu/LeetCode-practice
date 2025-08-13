#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    ListNode *next;
    int val;
    ListNode(){};
    ListNode(ListNode *next,int val):next(next),val(val){};
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA,*b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
ListNode *createNode(vector<int>& list) {
    if (list.empty()) return nullptr;
    ListNode *head = new ListNode(nullptr,list[0]);
    ListNode *cur = head;
    for (int i = 1;i < list.size();i++) {
        cur->next = new ListNode(nullptr,list[i]);
        cur = cur->next;
    }
    return head;
}
void printListNode(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void deleteListNode (ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    vector<int> listA = {4,1,8,4,5},listB = {5,6,1,8,4,5};
    ListNode *headA = createNode(listA);
    ListNode *headB = createNode(listB);
    ListNode* ans = getIntersectionNode(headA,headB);
    if (ans) cout << ans->val;
    else cout << "no IntersectionNode";
    return 0;
}
