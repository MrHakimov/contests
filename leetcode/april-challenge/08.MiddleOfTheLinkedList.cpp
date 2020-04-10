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
    ListNode* middleNode(ListNode* head) {
        ListNode *a = head;
        ListNode *b = head;

        while (b != nullptr && b->next != nullptr) {
            a = a->next;
            b = b->next->next;
        }

        return a;
    }
};
