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
        stack<int> st1;
        stack<int> st2;
        queue<int> st;
        ListNode* temp = l1;
        while (temp != NULL) {
            st1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp != NULL) {
            st2.push(temp->val);
            temp = temp->next;
        }
        int carry = 0;
        while (!st1.empty() && !st2.empty()) {
            int sum = st1.top() + st2.top() + carry;
            st1.pop();
            st2.pop();
            carry = sum / 10;
            sum = sum % 10;
            st.push(sum);
        }
        while (!st1.empty()) {
            int sum = st1.top() + carry;
            st1.pop();
            carry = sum / 10;
            sum = sum % 10;
            st.push(sum);
        }
        while (!st2.empty()) {
            int sum = st2.top() + carry;
            st2.pop();
            carry = sum / 10;
            sum = sum % 10;
            st.push(sum);
        }
        if (carry != 0) {
            st.push(carry);
        }
        ListNode*head=NULL;
        while(!st.empty())
        {
             if(head==NULL)
             {
                head=new ListNode(st.front());
                st.pop();
             }
             else
             {
                ListNode *t= new ListNode(st.front());
                st.pop();
                t->next=head;
                head=t;
             }
        }
        return head;
    }
};