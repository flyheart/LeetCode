/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 * You may not alter the values in the nodes, only nodes itself may be changed.

 * Only constant memory is allowed.

 * For example,
 * Given this linked list: 1->2->3->4->5

 * For k = 2, you should return: 2->1->4->3->5

 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (NULL == head || k <= 1) return head;
        ListNode* node = head;
        head = reverseKPairs(head, k);
        ListNode* temp = head;

        while (temp != node) {  // �����ڷ�תʱ��˵��δ��������β��
            ListNode* temp2 = node->next;
            temp = node->next = reverseKPairs(node->next, k);
            node = temp2;
        }

        return head;
    }
private:
    ListNode* reverseKPairs(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; NULL != node && i < k-1; ++i)
            node = node->next;
        if (NULL == node)   return head;    // ��Ա����k����ԭֵ����

        ListNode* next = node->next;    // !!!!!!!!
        ListNode* pre = node->next;
        ListNode* temp = NULL;
        while (head != next) { // ��д����head!=node->next, ��node->next�Ѹı�
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }

        return node;
    }
};

int main(void) {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    l1->next = l2;
    Solution so;
    ListNode* head = so.reverseKGroup(l1, 2);
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}