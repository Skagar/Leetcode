/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right)
            return head;

        ListNode* curr = head;
        ListNode* init = NULL;
        for (int i = 1; i < left; i++) {
            init = curr;
            curr = curr->next;
        }

        ListNode* c = curr;
        ListNode* prev = NULL;
        ListNode* fr = curr->next;
        for (int i = 0; i <= right - left; i++) {
            curr->next = prev;
            prev = curr;
            curr = fr;
            if (fr != NULL)
                fr = fr->next;
        }
        if (init != NULL)
            init->next = prev;
        else
            head = prev;

        c->next = curr;

        return head;
    }
};