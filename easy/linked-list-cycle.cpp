/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        if (head->next == NULL) {
            return false;
        }
        
        // Floyd's Tortoise and Hare Algorithm
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        // Writer Note: hare->next != NULL is edge case, because sometimes it might be null when the list's length is odd number
        while (tortoise->next != NULL && (hare->next != NULL && hare->next->next != NULL)) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            
            if (tortoise == hare) {
                tortoise = head;
                while (tortoise != hare) {
                    tortoise = tortoise->next;
                    hare = hare->next;
                }
                return true;
            }
        }
        
        return false;
    }
};


// Simpler solution:
// func hasCycle(head *ListNode) bool {
//     if head == nil || head.Next == nil {
//         return false
//     }
//     p1, p2 := head, head.Next
//     for p1 != p2 {
//         if p2 == nil || p2.Next == nil {
//             return false
//         }
//         p1 = p1.Next
//         p2 = p2.Next.Next
//     }
//     return true
// }