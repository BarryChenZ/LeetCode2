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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string tmp = "";
        path(root, ans, tmp);
        return ans;
    }
    void path(TreeNode* root, vector<string>&  ans, string tmp){
        if(!root) return;
        if(!root->left && !root->right){
            string temp = to_string(root->val);
            tmp += temp;
            ans.push_back(tmp);
            return;
        }
        string temp = to_string(root->val);
        tmp += temp + "->";
        cout << tmp << endl;
        path(root->left , ans, tmp);
        path(root->right, ans, tmp);
        tmp.erase(tmp.end()-1);
        tmp.erase(tmp.end()-1);
    }
};
