class Solution {
    struct TrieNode{
        bool word = false;
        vector<TrieNode*> nodes = vector<TrieNode*>(26);//pointer
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return vector<string>();
        
        TrieNode root;
        for(string& s : words) trie_insert_word(&root, s.c_str()); // 有結尾的字串
        //visit
        unordered_set<string> result;
        string word;
        vector<bool> visited(board.size()*board[0].size());
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                visit(board, &root, i, j, word, visited, result);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
    
    void trie_insert_word(TrieNode* node, const char* word){
        if(!*word){
            node->word = true;
        }
        else{
            int pos = *word - 'a';
            if(!node->nodes[pos]) node->nodes[pos] = new TrieNode(); //沒放過
            
            trie_insert_word(node->nodes[pos], word + 1);
        }
    }
    
    void visit(vector<vector<char>>& board, 
               TrieNode* node, 
               int i, int j, 
               string& word, 
               vector<bool>& visited, unordered_set<string>& result){
        int h = board.size();
        int w = board[0].size();
        if(i < 0 || j < 0 || i >= h || j >= w || visited[i*w + j] || !node->nodes[board[i][j] - 'a']) return; ///拜訪過 以及 不存在trieNode
        
        visited[i * w + j] = true;
        word += board[i][j];
        
        node = node->nodes[board[i][j] - 'a'];
        
        if(node->word) result.insert(word);
        
        visit(board, node, i - 1, j, word, visited, result);
        visit(board, node, i + 1, j, word, visited, result);
        visit(board, node, i, j - 1, word, visited, result);
        visit(board, node, i, j + 1, word, visited, result);
        
        word.pop_back();
        visited[i * w + j] = false;
    }
};
