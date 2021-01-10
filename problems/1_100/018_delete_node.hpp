
#include "lecode_list.hpp"

/*
 * @brief 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * @note  直接查找删除即可，O(n)
 */
ListNode *deleteNode(ListNode *head, int val){
    if(head == nullptr) return nullptr;
    if(head->val == val){
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        tmp = nullptr;
        return head;
    }

    ListNode *cur = head;
    while(cur && cur->next && cur->next->val != val){
        cur = cur->next;
    }

    if(cur == nullptr || cur->next == nullptr) 
        return head;

    ListNode *should_delete = cur->next;
    cur->next = cur->next->next;
    delete should_delete;
    should_delete = nullptr;
    return head;
}

#include "ios_include.hpp"

void test_018(){
    ListNode *head = ListNode::alloc({-3, 5, -99});
    cout<<head<<endl;
    head = deleteNode(head, -3);
    cout<<head<<endl;
}