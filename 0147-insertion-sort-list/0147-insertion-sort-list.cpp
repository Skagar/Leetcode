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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* Head = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            int data = temp->val;
            if (Head == NULL) {
                Head = new ListNode(data);
            } else {
                if (Head->val >= data) {
                    ListNode* n = new ListNode(data);
                    n->next = Head;
                    Head = n;
                } else if (Head->next == NULL && Head->val < data) {
                    ListNode* n = new ListNode(data);
                    Head->next = n;
                } else {
                    ListNode* trav = Head;
                    ListNode* prev = NULL;
                    while (trav != NULL && trav->val < data) {
                        prev = trav;
                        trav = trav->next;
                    }
                    ListNode* n = new ListNode(data);
                    n->next = prev->next;
                    prev->next = n;
                }
            }
            temp = temp->next;
        }
        return Head;
    }
};