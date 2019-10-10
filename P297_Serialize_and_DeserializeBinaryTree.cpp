/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur){
                s.append("x,");
                continue;
            }
            s.append(to_string(cur->val) + ",");
            if(!cur->left)  q.push(nullptr); else q.push(cur->left);
            if(!cur->right) q.push(nullptr); else q.push(cur->right);
        }
        
        int l = s.length();
        int i;
        for(i = l-1; i >= 0; i--){
            if(s[i] != 'x' && s[i] != ',')
                break;
        }
        
        s = s.substr(0, i + 1);
        s.append(1, ',');
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int l = data.length();
        if(l == 0) return nullptr;
        queue<TreeNode*> q;
        int i = 0, val, neg;
        
        while(i < l){
            if(data[i] == 'x'){
                q.push(nullptr);
                i += 2;
                continue;
            }
            val = 0;
            if(data[i] == '-'){
                neg = 1;
                i++;
            }
            else neg = 0;
            
            while(data[i] != ','){
                int digit = data[i] - '0';
                val = val * 10 + digit;
                i++;
            }
            if(neg) val = -1 * val;
            q.push(new TreeNode(val));
            i++;
        }
        
        TreeNode* root = q.front();
        TreeNode* cur;
        queue<TreeNode*> fq;
        fq.push(root);
        q.pop();
        while(!fq.empty()){
            cur = fq.front();
            fq.pop();
            if(!cur) continue;
            if(!q.empty()){
                cur->left = q.front();
                fq.push(q.front());
                q.pop();
            }
            if(!q.empty()){
                cur->right = q.front();
                fq.push(q.front());
                q.pop();
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
