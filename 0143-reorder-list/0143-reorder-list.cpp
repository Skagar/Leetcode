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
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        vector<int> brr;
        int i = 0;
        int j = arr.size() - 1;
        while (i <= j) {
            if (i != j) {
                brr.push_back(arr[i]);
                brr.push_back(arr[j]);
                i++;
                j--;
            } else {
                brr.push_back(arr[i]);
                i++;
            }
        }
        int index = 0;
        while (temp != NULL) {
            temp->val = brr[index++];
            temp = temp->next;
        }
    }
};