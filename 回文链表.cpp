#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    ListNode *next;
    int val;
    ListNode(int val):val(val),next(nullptr){};
    ListNode(ListNode* next,int val):next(next),val(val){};
};
/*
    找中间节点，从中间节点开始反转链表，双指针遍历。
*/
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
ListNode *middle(ListNode *head) {
    ListNode *slow = head,*fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(ListNode* head) {
    ListNode *mid = middle(head);
    ListNode *nxt = reverseList(mid);
    ListNode *cur = head;
    while (nxt) {//应该用nxt而非cur
        if (cur->val != nxt->val) return false;
        cur = cur->next;
        nxt = nxt->next;
    }
    return true;
}
ListNode *createListNode(vector<int>& list) {
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
    vector<int> vec = {1,2,2,1};
    ListNode *head = createListNode(vec);
    if (isPalindrome(head)) {
        cout << "true";
    }else{
        cout <<"false";
    }
    return 0;
}
