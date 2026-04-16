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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == NULL || k == 1)
            return head;
        vector<ListNode*> v;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head->next;
        int cnt = 0;
        int nodecnt = 0;
        while (curr != NULL) {
            nodecnt++;
            curr = curr->next;
        }
        curr = head;
        if (k == nodecnt) {
            while (curr->next != NULL) {
                curr->next = prev;
                prev = curr;
                curr = temp;
                temp = temp->next;
            }
            curr->next = prev;
            head = curr;
            return head;
        }
        while (nodecnt >= k) {
            while (cnt != k) {
                if (curr != NULL)
                    curr->next = prev;
                prev = curr;
                curr = temp;
                if (temp != NULL)
                    temp = temp->next;
                cnt++;
            }
            v.push_back(prev);
            prev = NULL;
            cnt = 0;
            nodecnt -= k;
        }
        if (!v.empty() && curr != NULL) {
            temp = v.back();
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
        for (int i = 0; i < v.size() - 1; i++) {
            temp = v[i];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            if (i + 1 < v.size())
                temp->next = v[i + 1];
        }
        if (!v.empty())
            head = v[0];
        return head;
    }
};