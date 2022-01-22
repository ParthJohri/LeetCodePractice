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
    public int getDecimalValue(ListNode head) {
        ListNode temp=head;
        int count=0,sum=0;
        while(temp!=null)
        {
            ++count;
            temp=temp.next;
        }
        while(head!=null)
        {
            sum=sum+head.val*(int)Math.pow(2,--count);
            head=head.next;
        }
        return sum;
    }
}