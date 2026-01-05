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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int sum = 0;
        int carry = -1;
        while (l1 != NULL && l2 != NULL) {
            if (carry == -1)
                sum = l1->val + l2->val;
            else {
                sum = l1->val + l2->val + carry;
                carry = -1;
            }
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            }
            if (head == NULL) {
                head = new ListNode(sum);
                tail = head;
                sum = 0;
            }

            else if (head != NULL) {
                ListNode* temp = new ListNode(sum);
                tail->next = temp;
                tail = tail->next;
                sum = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            if (carry == -1) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            } else {
                sum = l1->val + carry;
                carry=-1;
                if (sum > 9) {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                ListNode* temp = new ListNode(sum);
                tail->next = temp;
                tail = tail->next;
                l1 = l1->next;
                sum = 0;
            }
        }
        while (l2 != NULL) {
            if (carry == -1) {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            } else {
                sum = l2->val + carry;
                carry=-1;
                if (sum > 9) {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                ListNode* temp = new ListNode(sum);
                tail->next = temp;
                tail = tail->next;
                l2 = l2->next;
                sum = 0;
            }
        }
        if (carry != -1 && sum == 0) {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
            tail = tail->next;
        }
        return head;
    }
};