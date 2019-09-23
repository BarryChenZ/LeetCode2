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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        int size = 0;
        ListNode *it = head, *tmp;
        while(it) size++, it = it->next; //確認長度
        it = head;
        int i = 1;
        
        while(i < size/2){  //跑一半 反轉前半
            tmp = it->next;
            it->next = it->next->next;
            tmp->next = head;
            head = tmp;
            i++;
        }
        
        it = it->next;
        if(size%2 == 1) it = it->next;
        while(it != NULL){
            if(head->val != it->val) return false;
            head = head->next;
            it = it->next;
        }
        return true;
    }
};
