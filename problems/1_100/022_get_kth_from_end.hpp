#include "ios_include.hpp"

/*
 * @brief 使用快慢指针，当快指针前进k步之后启动慢指针，直到快指针到达末尾
 * @note    O(n)
 */
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *fast = head;
    ListNode *slow = head;
    for(int i = 0;i < k;i ++){
        if(fast){
            fast = fast->next;
        }else{
            return nullptr;
        }
    }

    while(fast){
        slow = slow->next;
        fast =fast->next;
    }

    return slow;
}


void test_022(){
    int k = 7;
    ListNode *ls = ListNode::alloc({1,2,3,4,5,6});
    cout<<ls<<endl;
    ListNode *head = getKthFromEnd(ls, k);
    cout<<head<<endl;
}