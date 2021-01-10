#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

/*
 * @brief 实现带头结点的双向链表     <-->[tail]<-->[头结点]<-->[head]<-->
 */
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        //当前链表包含头结点
        size = 0;
        head = new ListNode(-1);
        head->next = head;
        head->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size || size == 0)
            return -1;          //索引值非法

        ListNode *cur = head->next;
        while(index != 0){
            cur = cur->next;
            index--;
        }

        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *new_node = new ListNode(val);

        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;

        size ++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *new_node = new ListNode(val);

        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        new_node->next = head;
        size ++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index <= 0) return addAtHead(val);
        if(index == size) return addAtTail(val);
        
        ListNode *cur = head;
        while(index != 0){
            cur = cur->next;
            index --;
        }

        ListNode *new_node = new ListNode(val);
        new_node->next = cur->next;
        cur->next->prev = new_node;
        cur->next = new_node;
        new_node->prev = cur;

        size ++;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;

        ListNode *cur = head->next;
        while(index != 0)
        {
            index--;
            cur = cur->next;
        }

        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;

        if(cur) delete cur;
        cur = nullptr;
        size --;
        return;
    }

    void print(){
        ListNode *cur = head->next;
        cout<<"list: size=" << size<<endl;
        do
        {
            cout<<cur->val<<"  ";
            cur = cur->next;
            /* code */
        } while (cur != head);
        
        cout<<endl;
    }

private:
    class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode *prev;
    public:
        ListNode() : val(0), next(nullptr), prev(nullptr){}
        ListNode(int v) : val(v), next(nullptr), prev(nullptr){}
        ListNode(int v, ListNode *n, ListNode *p) : val(v), next(n), prev(p){}
    };

    ListNode* head;
    size_t size;
};


void test_707(){
    int index = 1;
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(1);
    obj->addAtHead(1);
    obj->print();
    obj->addAtTail(3);
    obj->print();
    obj->addAtIndex(1,2);
    obj->print();
    obj->deleteAtIndex(1);
    obj->print();
}