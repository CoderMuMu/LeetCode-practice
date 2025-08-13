#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val,ListNode* next):val(val),next(next){};
    ListNode(int val):val(val),next(nullptr){};
};
/*
    考察快慢指针的使用，以及哨兵节点，要删除倒数第n个节点，思路是让fast先走n步，保证slow和fast的距离始终为n
    这样fast走到空节点的时候，slow就是要删除的节点的上一个节点，因为这里使用了哨兵节点(有可能会删除头节点)，所有是
    上一个节点。
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0,head);
    ListNode *slow = dummy,*fast = dummy;
    while(n--){
        fast = fast->next;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
}
ListNode *createNode(vector<int>& list){
    if(list.empty()) return nullptr;
    ListNode *head = new ListNode(list[0]);
    ListNode *cur = head;
    for (int i = 1;i < list.size();i++) {
        cur->next = new ListNode(list[i]);
        cur = cur->next;
    }
    return head;
}
int main() {

    vector<int> head = {1,2,3,4,5};
    int n = 2;
    ListNode *l1 = createNode(head);
    ListNode *ans = removeNthFromEnd(l1,n);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
