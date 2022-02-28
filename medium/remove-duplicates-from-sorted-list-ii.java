/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
       while (head != null && head.next != null && head.val == head.next.val) {
           head = head.next;
           
           // skip the last duplicate value
           if (head.next == null || head.val != head.next.val) {
               head = head.next;
           }
       }
        
        ListNode result = head;
        ListNode prev = null;
        ListNode curr = result;
        
        while (curr != null && curr.next != null) {
            if (curr.val == curr.next.val) {
                curr.next = curr.next.next;
                if (curr.next == null || curr.val != curr.next.val) {
                    prev.next = curr.next;
                    curr = prev.next;
                }
                continue;
            }
            
            prev = curr;
            curr = curr.next;
        }
        
        return result;
    }
}