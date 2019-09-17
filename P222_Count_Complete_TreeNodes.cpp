/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        //確認高度
        int h = 0;
        height(root, h, 1);
        //確認缺口
        int lose = 0;
        lastEnd(root, lose, h, 1);
        cout << h << " "<< lose;
        return pow(2, h) - (1 + lose);
        
    }
    void height(TreeNode* root, int& h, int i){
        if(!root){
            h = i - 1;
            return;
        }
        height(root->left, h, i + 1);
    }
    void lastEnd(TreeNode* root, int& lose, int h, int i){
        if(i >= h) return;
        if(root->right && root->left && i == h -1) return;
        if(!root->right){
            lose++;
            if(!root->left){
                lose++;
            }
            return;
        }
        lastEnd(root->right, lose, h, i + 1);
        lastEnd(root->left, lose, h, i + 1);
        
        
    }
};
