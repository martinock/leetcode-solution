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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        
        int toDelete = count - n;
        if (toDelete <= 0) {
            return head->next;
        }
        
        int p = 0;
        curr = head;
        while (curr->next != NULL && curr->next->next != NULL && p != toDelete-1) {
            curr = curr->next;
            p++;
        }
        
        if (curr->next != NULL) {
            curr->next = curr->next->next;
        }
        
        return head;
    }
};