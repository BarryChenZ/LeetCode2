class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sort_vec;
        trace(sort_vec, root);
        return sort_vec[k - 1];
    }
    void trace(vector<int>& sort_vec, TreeNode* root){
        if(!root) return;
        trace(sort_vec, root->left);
        sort_vec.push_back(root->val);
        trace(sort_vec, root->right);
    }
};
