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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* frwrd = head->next;
        head = head->next;
        while (curr != NULL && frwrd != NULL) {
            if (prev != NULL)
                prev->next = frwrd;
            prev = curr;
            curr->next = frwrd->next;
            frwrd->next = curr;
            curr = curr->next;
            if (curr != NULL)
                frwrd = curr->next;
        }
        return head;
    }
};