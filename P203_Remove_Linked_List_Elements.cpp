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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = head;
        while(res){
            if(res->val != val) break;
            res = res->next;
        }
        if(res == NULL || res->next == NULL) return res;
        ListNode* tmp = res;
        ListNode* tmp_next = tmp->next;
        while(true){
            if(tmp_next->val == val){
                if(tmp_next->next != NULL){
                    tmp->next = tmp_next->next;
                    tmp_next = tmp_next->next;
                }
                else{
                    tmp->next = NULL;
                    break;
                }
            }
            else{
                tmp = tmp->next;
                if(tmp->next == NULL) break;
                tmp_next = tmp->next;
            }
        }
        return res;
    }
};
