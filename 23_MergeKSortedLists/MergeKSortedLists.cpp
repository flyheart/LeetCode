/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        /*
        // Time Limit Exceeded, ±º‰∏¥‘”∂»£∫O(n1+(n1+n2)+(n1+n2+n3)+...+(n1+n2+...+nk))
        ListNode* head = NULL;
        int size = lists.size();
        for (int i = 0; i < size; ++i) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
        */
        int size = lists.size();
        if (0 == size)  return NULL;
        return sort(lists, 0, size - 1);

    }
private:
    ListNode* sort(vector<ListNode*>& lists, int start, int end) {
        if (start > end)    return NULL;
        if (start == end)   return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = sort(lists, start, mid);
        ListNode* l2 = sort(lists, mid+1, end);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        if (NULL == l2) return l1;

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) { temp->next = l1; temp = temp->next; l1 = l1->next; }
            else                    { temp->next = l2; temp = temp->next; l2 = l2->next; }
        }
        if (l1 == NULL) temp->next = l2;
        if (l2 == NULL) temp->next = l1;
        temp = head->next;
        delete head;
        return temp;
    }
};