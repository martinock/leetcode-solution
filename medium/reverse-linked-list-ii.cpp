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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right) {
            return head;
        }
        
        int currPos = 1;
        ListNode* curr = head;
        ListNode* result = NULL;
        ListNode* currResult = NULL;
        ListNode* partialResult = NULL;
        
        if (left != 1) {
            currPos = 2;
            curr = head->next;
            result = new ListNode(head->val);
            currResult = result;
        }
        
        while (curr != NULL) {
            ListNode* currNode = new ListNode(curr->val);
            
            if (currPos == left) {
                partialResult = currNode;
            } else if (currPos > left && currPos < right) {
                currNode->next = partialResult;
                partialResult = currNode;
            } else if (currPos == right) {
                currNode->next = partialResult;
                partialResult = currNode;
                if (currResult == NULL) {
                    result = partialResult;
                    currResult = result;
                } else {
                    currResult->next = partialResult;
                }
                while (currResult->next != NULL) {
                    currResult = currResult->next;
                }
            } else {
                currResult->next = currNode;
                currResult = currResult->next;
            }
            
            curr = curr->next;
            currPos++;
        }
        
        return result;
    }
};
