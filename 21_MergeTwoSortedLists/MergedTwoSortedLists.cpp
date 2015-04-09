/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        if (NULL == l2) return l1;
        ListNode* head = new ListNode(-1); // ÁÙÊ±Í·
        ListNode* temp = head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val)  { temp->next = l1; l1 = l1->next; }
            else                     { temp->next = l2; l2 = l2->next; }
            temp = temp->next;
        }
        if (l1 == NULL) temp->next = l2;
        if (l2 == NULL) temp->next = l1;
        temp = head->next;
        delete head;
        return temp;
    }
};