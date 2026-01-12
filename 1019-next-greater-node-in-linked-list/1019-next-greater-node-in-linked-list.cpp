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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head->next;
        while (temp != NULL) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        while (curr != NULL) {
            while (!st.empty() && curr -> val >= st.top()) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top());
            st.push(curr->val);
            curr=curr->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};