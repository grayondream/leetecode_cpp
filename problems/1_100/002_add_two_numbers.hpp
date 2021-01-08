#include "lecode_list.hpp"

/*
 * @brief 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * @note    解法很直接从头到尾遍历相加即可，唯一需要注意的好似进位, 算法复杂度O(n)
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2){
        return nullptr;
    }

    int cax = 0;
    ListNode tmp;
    ListNode *head = &tmp;
    while(l1 && l2){
        int val = l1->val + l2->val + cax;
        ListNode *new_node = new ListNode(val % 10, nullptr);
        cax = val / 10;
        head->next = new_node;
        
        head = head->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1){
        int val = l1->val + cax;
        ListNode *new_node = new ListNode(val % 10, nullptr);
        cax = val / 10;
        head->next = new_node;
        head = head->next;
        l1 = l1->next;
    }

    while(l2){
        int val = l2->val + cax;
        ListNode *new_node = new ListNode(val % 10, nullptr);
        cax = val / 10;
        head->next = new_node;
        l2 = l2->next;
        head = head->next;
    }

    if(cax != 0){
        ListNode *new_node = new ListNode(cax, nullptr);
        head->next = new_node;
    }

    return tmp.next;
}


using std::cout;
using std::endl;


void test_002(){
    ListNode *l1 = ListNode::alloc({9, 9});//(10, 0, 9);
    ListNode *l2 = ListNode::alloc({9, 9, 9, 9, 9});//(10, 0, 9);
    cout<<l1<<endl;
    cout<<l2<<endl;
    ListNode* ret = addTwoNumbers(l1, l2);
    cout<<ret<<endl;
}