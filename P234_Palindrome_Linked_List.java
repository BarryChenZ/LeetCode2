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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        ListNode fristHalfHead = head;
        ListNode firstHalfTail = slow;
        ListNode secondHalfHead = reverseList(firstHalfTail.next);
        
        boolean result = isEqual(fristHalfHead, secondHalfHead);
        
        
        return result;
    }
    public ListNode reverseList(ListNode head){
        ListNode pre = null;
        ListNode cur = head;
        
        while(cur != null){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    public boolean isEqual(ListNode h1, ListNode h2){
        while(h1 != null && h2 != null){
            if(h1.val != h2.val){
                return false;
            }
            
            h1 = h1.next;
            h2 = h2.next;
        }   
        return true;
    }
    
}
