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
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int n = lists.size();
        if (n == 0)
            return NULL;
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        while (pq.size() > 0) {

            ListNode* topele = pq.top();
            pq.pop();
            if (head == NULL) {
                head = topele;
                tail = head;
            } else {
                tail->next = topele;
                tail = tail->next;
            }
            if (topele->next != NULL)
                pq.push(topele->next);
        }
        return head;
    }
};