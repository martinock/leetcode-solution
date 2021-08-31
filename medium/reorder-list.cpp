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
        stack<int> s;
        int count = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            count++;
            s.push(curr->val);
            curr = curr->next;
        }
        
        int mid = count/2;
        int i = 0;
        curr = head;
        while (i < mid) {
            ListNode* tail = curr->next;
            curr->next = new ListNode(s.top(), tail);
            s.pop();
            curr = curr->next;
            if (i < mid - 1 || ((i == mid-1) && count%2 > 0)) {
                curr = curr->next;
            }
            i++;
        }
        curr->next = NULL;
    }
};