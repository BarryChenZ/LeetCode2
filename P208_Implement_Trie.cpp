
class Trie {
    unordered_map<char, Trie*> children;
    bool wordEndHere;
public:
    
    /** Initialize your data structure here. */
    Trie() {
        wordEndHere = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(auto s : word){
            if(cur->children.find(s) == cur->children.end()){
                cur->children[s] = new Trie();
            }
            cur = cur->children[s];
        }
        cur->wordEndHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(auto s : word){
            if(cur->children.find(s) == cur->children.end()){
                return false;
            }
            cur = cur->children[s];
        }
        return cur->wordEndHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for(auto s : prefix) {
            if( cur->children.find(s) == cur->children.end() ) {
                return false;
            }
            cur = cur->children[s];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
