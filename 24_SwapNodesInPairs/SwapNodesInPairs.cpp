/**
 * Given a linked list, swap every two adjacent nodes and return its head.

 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.

 * Your algorithm should use only constant space. You may not modify the values in the list, 
 * only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode* head) {
        /**
        * 
        * if (NULL == head)   return NULL;
        * if (head->next == NULL)  return head;
        * ListNode* temp = head->next;
        * head->next = temp->next;
        * temp->next = head;
        * head->next = swapPairs(head->next);
        * return temp;
        */
        if (NULL == head)   return NULL;
        ListNode* list = new ListNode(-1);
        list->next = head;
        ListNode* pre = list;
        while (NULL != head && NULL != head->next) {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            pre->next = tmp;
            pre = head;
            head = head->next;
        }
        return list->next;
    }
};

int main(void) {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    Solution so;
    ListNode* h = so.swapPairs(h1);
    while (NULL != h) {
        cout << h->val << "->";
        h = h->next;
    }
    cout << "NULL" << endl;

    return 0;
}