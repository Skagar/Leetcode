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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp = head;
        if (k == 0 ||head==NULL)
            return head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        reverse(arr.begin(), arr.end());
        int n = arr.size();
        int c = 0;
        int v = k % n;
        int t = v - 1;
        for (int i = 0; i < v / 2; i++) {
            swap(arr[i], arr[t--]);
        }
        for (int i = v; i < arr.size(); i++) {
            if (i < n)
                swap(arr[i], arr[--n]);
            else
                break;
        }
        while (temp != NULL) {
            temp->val = arr[c++];
            temp = temp->next;
        }
        return head;
    }
};