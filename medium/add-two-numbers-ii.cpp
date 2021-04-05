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
        int s1 = 0;
        int s2 = 0;
        ListNode* curr = l1;
        ListNode* curr2 = l2;
        while (curr != NULL || curr2 != NULL) {
            if (curr != NULL) {
                s1++;
                curr = curr->next;
            }
            
            if (curr2 != NULL) {
                s2++;
                curr2 = curr2->next;
            }
        }
        int carry = 0;
        ListNode* result;
        
        if (s1 == s2) {
            result = addRecursive(l1, l2, &carry);
        } else {
            int diff = abs(s1 - s2);
            ListNode* curr;
            if (s1 > s2) {
                curr = l1;
            } else {
                curr = l2;
            }
            
            for (int i = 0; i < diff; ++i) {
                curr = curr->next;
            }
            
            if (s1 > s2) {
                result = addRecursive(curr, l2, &carry);
                addRemaining(curr, l1, &carry, &result);
            } else {
                result = addRecursive(l1, curr, &carry);
                addRemaining(curr, l2, &carry, &result);
            }
        }
        
        if (carry > 0) {
            return new ListNode(1, result);
        }
        return result;
    }
    
    ListNode* addRecursive(ListNode* l1, ListNode* l2, int* carry) {
        if (l1 == NULL) {
            return NULL;
        }
        
        ListNode* result = new ListNode();
        result->next = addRecursive(l1->next, l2->next, carry);
        
        int val = l1->val + l2->val + *carry;
        *carry = val / 10;
        val = val % 10;
        
        result->val = val;
        
        return result;
    }
    
    void addRemaining(ListNode* curr, ListNode* l, int* carry, ListNode** result) {
        if (l == curr) {
            return;
        }
        
        addRemaining(curr, l->next, carry, result);
        
        int val = l->val + *carry;
        *carry = val / 10;
        val = val % 10;
        
        *result = new ListNode(val, *result);
    }
};