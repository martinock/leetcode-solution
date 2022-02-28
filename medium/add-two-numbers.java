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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode curr1 = l1;
        ListNode curr2 = l2;
        ListNode result = null;
        ListNode currResult = null;
        
        int carry = 0;
        do {
            int digit = curr1.val + curr2.val + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            if (result == null) {
                result = new ListNode(digit);
                currResult = result;
            } else {
                currResult.next = new ListNode(digit);
                currResult = currResult.next;
            }
            curr1 = curr1.next;
            curr2 = curr2.next;
        } while (curr1 != null && curr2 != null);
                
        while (curr1 != null) {
            int digit = curr1.val + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            currResult.next = new ListNode(digit);
            currResult = currResult.next;
            curr1 = curr1.next;
        }
        
        while (curr2 != null) {
            int digit = curr2.val + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            currResult.next = new ListNode(digit);
            currResult = currResult.next;
            curr2 = curr2.next;
        }
        
        if (carry > 0) {
            currResult.next = new ListNode(carry);
        }
        
        return result;
    }
}