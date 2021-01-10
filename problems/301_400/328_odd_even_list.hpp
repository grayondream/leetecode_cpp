#include "lecode_list.hpp"

/*
 * @brief 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性
 * @note    将奇数位的结点移动到最前即可时间复杂度O(n)
 */
ListNode* oddEvenList(ListNode *head){
    ListNode *even_head = new ListNode(-1);
    even_head->next = head;
    ListNode *even_cur = even_head;

    ListNode *odd_head = new ListNode(-1);
    ListNode *odd_cur  = odd_head;

    while(even_cur && even_cur->next){
        odd_cur->next = even_cur->next;
        even_cur->next = even_cur->next->next;
        odd_cur->next->next = nullptr;

        odd_cur = odd_cur->next;
        even_cur = even_cur->next;
        ;
    }

    odd_cur->next = even_head->next;
    head = odd_head->next;
    delete odd_head;
    delete even_head;
    return head;
}

#include <iostream>
using std::cout;
using std::endl;

void test_328(){
    ListNode *head = ListNode::alloc({2,1,3,5,6,4,7});
    cout<<head<<endl;
    head = oddEvenList(head);
    cout<<head<<endl;
}