
#include <ostream>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <random>
#include <ctime>


using std::uniform_int_distribution;
using std::default_random_engine;
using std::vector;
using std::initializer_list;
using std::ostream;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *n) : val(x), next(n){}
    
public:
    static ListNode *alloc(const initializer_list<int> &ls){
        ListNode tmp;
        ListNode *head = &tmp;
        for(int val : ls){
            head->next = new ListNode(val, nullptr);
            head = head->next;
        }

        head = tmp.next;
        return head;
    }

    static ListNode *alloc(const vector<int> &ls){
        ListNode tmp;
        ListNode *head = &tmp;
        for(int val : ls){
            head->next = new ListNode(val, nullptr);
            head = head->next;
        }

        head = tmp.next;
        return head;
    }

    static ListNode *alloc(size_t len, int min_border = 0, int max_border = 100){
        ListNode tmp;
        ListNode *head = &tmp;
        default_random_engine rand(time(NULL));
        uniform_int_distribution<int> urand(min_border, max_border);

        for(int i = 0;i < len;i ++){
            head->next = new ListNode(urand(rand), nullptr);
            head = head->next;
        }

        head = tmp.next;
        return head;
    }

    static void destroy(ListNode *head){
        while(head){
            ListNode *tmp = head;
            head = head->next;
            if(tmp) delete tmp;
            tmp = nullptr;
        }
    }
};

ostream& operator<<(ostream& os, const ListNode* head){
    while(head){
        os<<head->val<<"\t";
        head = head->next;
    }

    return os;
}
