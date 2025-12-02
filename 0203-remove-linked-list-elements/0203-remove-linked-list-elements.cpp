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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {

            if (temp->val == val && temp == head) {
                temp = temp->next;
                head->next = NULL;
                head = temp;
            } else if (temp->val == val) {
                prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next = NULL;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};