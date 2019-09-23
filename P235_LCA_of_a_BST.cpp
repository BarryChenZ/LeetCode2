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
    int time = 0;
    int low = INT_MAX;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        if (left != nullptr && left != p && left != q)
            return left;
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        if (right != nullptr && right != p && right != q)
            return right;
        if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        if ((left == p || left == q) && (right == p || right == q))
            return root;
        return nullptr;
    }
};
