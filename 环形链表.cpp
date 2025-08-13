#include <bits/stdc++.h>
using namespace std;
/*
    考察快慢指针：循环的条件就是fast不为空并且fast->next不为空
    fast的最终值为nullptr
*/
struct ListNode {
    ListNode *next;
    int val;
    ListNode(int val):next(nullptr),val(val){};
    ListNode(ListNode* next,int val):next(next),val(val){};
};
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {//环形链表需要判断的是不是同一个节点而非值，即会收到相同值的影响也会收到空指针的影响报错
            return true;
        }
    }
    return false;
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

    vector<int> list = {3,2,0,-4};
    ListNode *head = createListNode(list);
    cout << hasCycle(head);
    return 0;
}
