#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    ListNode *next;
    int val;
    ListNode(){};
    ListNode(int val):next(nullptr),val(val){};
    ListNode(ListNode *next,int val):next(next),val(val){};
};
/*
    考察链表的拼接，基本使用
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *cur = new ListNode();
    ListNode *ans = cur;
    while(l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if(l1){
        cur->next = l1;
    }else{
        cur->next = l2;
    }
    return ans->next;
}
ListNode *createNode(vector<int> &list){
    if (list.empty()) return nullptr;
    ListNode *head = new ListNode(list[0]);
    ListNode *cur = head;
    for (int i = 1;i < list.size();i++) {
        cur->next = new ListNode(list[i]);
        cur = cur->next;
    }
    return head;
}
int main() {

    vector<int> list1 = {1,2,4},list2 = {1,3,4};
    ListNode *l1 = createNode(list1),*l2 = createNode(list2);
    ListNode *l3 = mergeTwoLists(l1,l2);
    while(l3){
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}
