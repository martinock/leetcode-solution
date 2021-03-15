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
    ListNode* middleNode(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* currHalf = head;
        int idx = 0;
        int idxHalf = 0;
        while (curr != NULL) {
            curr = curr->next;
            if (curr == NULL) {
                break;
            }
            idx++;
            while (idxHalf < idx/2) {
                currHalf = currHalf->next;
                idxHalf++;
            }
        }
        if (idx % 2 != 0) {
            currHalf = currHalf->next;
        }
        return currHalf;
    }
};