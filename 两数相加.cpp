#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    ListNode *next;
    int val;
    ListNode(int val):next(nullptr),val(val){};
    ListNode(){};
};
/*
    考察相加过程的模拟能力
    切记链表题目，如果创建了临时节点之类的变量，需要delete，回收资源
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *cur = new ListNode();
    ListNode *head = cur;
    while (l1 || l2 || carry){
        if (l1){
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2){
            carry += l2->val;
            l2 = l2->next;
        }
        cur->next = new ListNode(carry % 10);
        carry /= 10;
        cur = cur->next;
    }
    ListNode *ans = head->next;
    delete head;
    return ans;
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

    vector<int> list1 = {2,4,3},list2 = {5,6,4};
    ListNode *l1 = createNode(list1),*l2 = createNode(list2);
    ListNode *l3 = addTwoNumbers(l1,l2);
    while(l3){
        cout << l3->val << " ";
        l3 = l3->next;
    }

    return 0;
}
