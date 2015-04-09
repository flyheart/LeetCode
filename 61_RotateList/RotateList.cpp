// RotateList.cpp

/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */

#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (NULL==head || NULL==head->next || 0==k) return head;
        int count = 1;
        ListNode* temp = head;
        while (NULL != temp->next) {
            ++count;
            temp = temp->next;
        }
        temp->next = head;
        k = k % count;
        while (--count >= k) {  // 注意其中蕴含的思想，循环，以对应k==0的情况。
            temp = temp->next;
        }
        ListNode* first = temp->next;
        temp->next = NULL;

        return first;
    }
};

int main(void) {
    Solution so;

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l5->next = NULL;

    ListNode* head = so.rotateRight(l1, 5);
    while (NULL != head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}