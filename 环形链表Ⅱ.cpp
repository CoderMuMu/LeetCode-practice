#include <bits/stdc++.h>
using namespace std;
/*
    在判断是否有环的基础上，要找出环的入口点在哪，这里需要一个思维的跳跃，或者说是数学思维
    设头节点到入口点的距离为a，入口点到快慢指针的相遇点的距离为b，相遇点到入口点的距离为c
    则有
    慢指针的移动距离为a+b,快指针的移动距离为a+b+k(b+c),由于两者的速度关系，有以下等式
    2*(a+b)=a+b+k(b+c)，式子变形得a-c=(k-1)(b+c),由式子与距离关系得，慢指针从相遇点走c步到入口点
    同时，头节点从起点走c步，那么他到入口点得距离就还剩下a-c，由以上等式得剩下的距离一定是环长的整数倍
    所以无论如何，只要头节点和慢指针的速率相同，那么就一定能在环的入口点相遇。
    本题最好通过画图，得出等式。
*/
struct ListNode {
    ListNode *next;
    int val;
    ListNode(int val):next(nullptr),val(val){};
    ListNode(ListNode* next,int val):next(next),val(val){};
};
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head,*fast = head;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            while (slow != head){
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main() {

    

    return 0;
}
