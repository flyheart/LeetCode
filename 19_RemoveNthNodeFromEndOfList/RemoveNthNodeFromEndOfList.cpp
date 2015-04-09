/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* start = head;
        ListNode* end = head;
        int i;
        for (i = 0; i < n+1 && end != NULL; ++i)
            end = end->next;
        if (i < n+1 && NULL == end) {  // ���ɾ�����ǵ�һ��Ԫ��
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (end != NULL) {
            start = start->next;
            end = end->next;
        }
        ListNode* temp = start->next;
        start->next = start->next->next;
        delete temp;
        return head;
    }
};