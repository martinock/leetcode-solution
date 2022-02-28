/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashMap<ListNode, Boolean> store = new HashMap<>();
        ListNode currA = headA;
        ListNode currB = headB;
        
        while (currA != null) {
            store.put(currA, true);
            currA = currA.next;
        }
        
        while (currB != null) {
            if (store.containsKey(currB)) {
                return currB;
            }
            store.put(currB, true);
            currB = currB.next;
        }
        
        return null;
    }
}