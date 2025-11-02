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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        if (list1 == NULL && list2 != NULL)
            return list2;
        if (list1 != NULL && list2 == NULL)
            return list1;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        while (h1 != NULL && h2 != NULL) {
            if (h1->val > h2->val) {
                if (head == NULL) {
                    head = new ListNode(h2->val);
                    tail = head;
                } else {
                    ListNode* temp = new ListNode(h2->val);
                    tail->next = temp;
                    tail = tail->next;
                }
                h2 = h2->next;
            } else if (h1->val < h2->val) {
                if (head == NULL) {
                    head = new ListNode(h1->val);
                    tail = head;
                } else {
                    ListNode* temp = new ListNode(h1->val);
                    tail->next = temp;
                    tail = tail->next;
                }
                h1 = h1->next;
            } else {
                if (head == NULL) {
                    head = new ListNode(h2->val);
                    tail = head;
                    ListNode* temp = new ListNode(h2->val);
                    tail->next = temp;
                    tail = tail->next;
                } else {
                    ListNode* temp1 = new ListNode(h2->val);
                    tail->next = temp1;
                    tail = tail->next;
                    ListNode* temp2 = new ListNode(h2->val);
                    tail->next = temp2;
                    tail = tail->next;
                }
                h1 = h1->next;
                h2 = h2->next;
            }
        }
        while (h1 != NULL) {
            ListNode* temp = new ListNode(h1->val);
            tail->next = temp;
            tail = tail->next;
            h1 = h1->next;
        }
        while (h2 != NULL) {
            ListNode* temp = new ListNode(h2->val);
            tail->next = temp;
            tail = tail->next;
            h2 = h2->next;
        }
        return head;
    }
};