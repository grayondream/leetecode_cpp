#include "ios_include.hpp"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode *head = nullptr;
    if(l1->val < l2->val){
        head = l1;
        l1 = l1->next;
    }else{
        head = l2;
        l2 = l2->next;
    }

    ListNode *cur = head;
    while(l1 && l2){
        ListNode *insert_node = nullptr;
        if(l1->val < l2->val){
            insert_node = l1;
            l1 = l1->next;
        }else{
            insert_node = l2;
            l2 = l2->next;
        }

        cur->next = insert_node;
        cur = cur->next;
    }

    if(l1){
        cur->next = l1;
    }

    if(l2){
        cur->next = l2;
    }

    return head;
    
}