#include "ios_include.hpp"

/*
 * @brief 合并两个升序有序链表，O(n)
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2) return nullptr;
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

    ListNode* ret_cur = head;
    while(l1 && l2){
        ListNode *cur = nullptr;
        if(l1->val < l2->val){
            cur = l1;
            l1 = l1->next;
        }else{
            cur = l2;
            l2 = l2->next;
        }

        ret_cur->next = cur;
        ret_cur = ret_cur->next;
    }

    if(l1){
        ret_cur->next = l1;
    }

    if(l2){
        ret_cur->next = l2;
    }

    return head;
}