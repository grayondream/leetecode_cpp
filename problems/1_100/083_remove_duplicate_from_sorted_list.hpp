#include "ios_include.hpp"

/*
 * @brief 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次
 */
ListNode* deleteDuplicates(ListNode* head) {
    ListNode * it = head;

    while(it){
        while(it && it->next && it->val == it->next->val){
            ListNode *tmp = it->next;
            it->next = it->next->next;
            delete tmp;
            tmp = nullptr;
        }

        it = it->next;
    }

    return head;
}