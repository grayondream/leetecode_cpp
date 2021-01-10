#include "ios_include.hpp"


ListNode *reverseList(ListNode *head){
    if(!head || !head->next) return head;
        ListNode *ret_head = head;
        ListNode *cur = head->next;
        ret_head->next = nullptr;
        while(cur){
            ListNode *tmp = cur;
            cur = cur->next;

            tmp->next = ret_head;
            ret_head = tmp;
        }

        return ret_head;
}

void test_024(){
    ListNode *head = ListNode::alloc({1,2,3,4});
    cout<<head<<endl;
    head = reverseList(head);
    cout<<head<<endl;
    return;
}