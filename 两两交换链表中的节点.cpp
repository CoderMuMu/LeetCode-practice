#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){};
    ListNode(int val,ListNode *next):val(val),next(next){};
};
ListNode* swapPairs(ListNode* head) {
    
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





    return 0;
}
