/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
// Writer notes: this called Floyd's tortoise and hare algorithm
// Iterate the list with 2 pointers where one pointer has twice speed (the hare). If there's cycle, eventually it will met.
// When the tortoise and hare met, once again, we will try to keep iterating the tortoise and create one more pointer iterating from head.
// It will guaranteed that the tortoise distance from the cycle equals to the distance from head to the cycle.
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        
        ListNode curr = head;
        ListNode curr2 = head;
        while (true) {
            curr = curr.next;
            if (curr == null) {
                return null;
            }
            
            curr2 = curr2.next;
            if (curr2 == null) {
                return null;
            }
            curr2 = curr2.next;
            if (curr2 == null) {
                return null;
            }
            
            
            if (curr == curr2) {
                break;
            }
        }
                
        ListNode check1 = head;
        ListNode check2 = curr;
        
        while (check1 != check2) {
            check1 = check1.next;
            check2 = check2.next;
        }
        
        return check1;
    }
}