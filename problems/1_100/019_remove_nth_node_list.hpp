#include "ios_include.hpp"

/*
 * @brief 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
 * @note 首先找到倒数第n+1个节点，使用快慢指针寻找
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head)
        return head;

    ListNode *fast = head;
    n = n + 1;
    while (fast && n) {
        n--;
        fast = fast->next;
    }

    if (n >= 1) { //链表倒数第n个节点是头结点
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    ListNode *slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    tmp = nullptr;
    return head;
}