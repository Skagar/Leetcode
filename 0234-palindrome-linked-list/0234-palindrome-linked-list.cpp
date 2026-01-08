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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        bool flag = true;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (arr[i] != arr[j])
                flag = false;
            i++;
            j--;
        }
        if (flag == false)
            return false;
        return true;
    }
};