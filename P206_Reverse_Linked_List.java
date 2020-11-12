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
    public ListNode reverseList(ListNode head) { 
        if(head == null || head.next == null) return head;
        ListNode previous = new ListNode();
        ListNode current = new ListNode();
        ListNode preceeding = new ListNode(0);
        previous = null;
        current = head;
        preceeding = head.next;
        while(preceeding != null){
            current.next = previous;
            previous = current;
            current = preceeding;
            preceeding = preceeding.next;
        }
        current.next = previous;
        head = current;
        return head;
    }
}
