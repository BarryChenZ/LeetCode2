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
    ListNode* temp = new ListNode(0);
    ListNode* reverseList(ListNode* head) {
        ListNode* res = temp;
        if(!head) return head;
        Reverse(head);
        return res->next;
    }
    void Reverse(ListNode* head){
        if(head->next) Reverse(head->next);
        temp->next = head;
        temp = temp -> next;
        temp->next = NULL;
        return;
    }
};
