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
    void deleteNode(ListNode* node) {
        ListNode* front,*rear;
        front = node;
        rear = front->next;
        while(rear->next != NULL){
            front->val = rear->val;
            rear = rear->next;
            front = front->next;
        }
        front->val = rear->val;
        front->next = NULL;
    }
};
