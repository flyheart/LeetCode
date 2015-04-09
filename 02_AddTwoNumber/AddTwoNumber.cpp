/*
You are given two linked lists representing two non-negative numbers. The digits 
are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
看错题意，误以为逆序输出
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* pre1 = NULL;
        ListNode* pre2 = l1;
        int carry = 0;
        while(l1 && l2) {
            ListNode* pre2 = l1;
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
            pre2->next = pre1;
            pre1 = pre2;
        }
        
        
        return pre2;
    }
};
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = l1;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 && l2) {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            tail->next = l2;
        }
        while (l1) {
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
            tail = l1;
            l1 = l1->next;

        }
        while (l2) {
            l2->val += carry;
            carry = l2->val / 10;
            l2->val %= 10;
            tail = l2;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* node = new ListNode(carry);
            tail->next = node;
        }
        
        return head;
    }
};