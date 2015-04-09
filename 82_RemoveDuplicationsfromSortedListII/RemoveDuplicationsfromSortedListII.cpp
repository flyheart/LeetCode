// RemoveDuplicationsfromSortedListII.cpp

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

#include <iostream>
using namespace std;

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head)   return head;
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* prev = first;
        bool flag = false;  // is duplicate or not
        while (NULL != head->next) {
             if (head->val == head->next->val) {
                 flag = true;
                 // prev = head;
                 head = head->next;
             }
             else {
                 if (true == flag) {
                    prev->next = head->next;
                    flag = false;
                 }
                 else prev = head;
                 head = head->next;
             }
        }
        if (true == flag) { prev->next = head->next; }

        head = first->next;
        delete first;

        return head;
    }
};

int main(void) {
    Solution so;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(1);
    ListNode* l3 = new ListNode(2);
    l1->next = l2; l2->next = l3;

    ListNode* l = so.deleteDuplicates(l1);

    while (NULL != l) {
        cout << l->val << " -> ";
        l = l->next;
    }
    cout << "NULL" << endl;

    return 0;
}