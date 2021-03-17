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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* left = head;
        ListNode* right = slow->next; 
        slow->next = NULL;
        
        left = sortList(left); 
        right = sortList(right);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left,ListNode* right) {
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        }
        
        ListNode* result;
        if (left->val > right->val) {
            result = right;
            result->next = merge(left, right->next);
        } else {
            result = left;
            result->next = merge(left->next, right);
        }
        
        return result;
    }
};