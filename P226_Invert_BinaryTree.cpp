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
    TreeNode* invertTree(TreeNode* root) {
        inverse(root);
        return root;
    }
    void inverse(TreeNode* root){
        if(!root) return;
        if(root->left && root->right){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left  = temp;
            inverse(root->left);
            inverse(root->right);
        }
        else if(root->left && !root->right){
            root->right = root->left;
            root->left = NULL;
            inverse(root->right);
        }
        else if(!root->left && root->right){
            root->left  = root->right;
            root->right = NULL;
            inverse(root->left);
        }
        else{
            return;
        }
    }
};
