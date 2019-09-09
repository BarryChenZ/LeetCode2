class WordDictionary {
    struct Node {
        bool valid;
        unique_ptr<Node> childs[26];
        Node(){
            valid = false;
        }
    };
    Node dict;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = &dict;
        
        for(char ch : word){
            if(!node->childs[ch - 'a']){
                node->childs[ch - 'a'] = make_unique<Node>();
            }
            node = node->childs[ch - 'a'].get();
        }
        node->valid = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<Node*> qu;
        qu.push(&dict);
        
        for(char ch : word){
            int size = qu.size();
            if(size == 0){
                return false;
            }
            for(int i = 0; i < size; i++){
                Node* node = qu.front();
                qu.pop();
                if(ch == '.'){
                    for(int i = 0; i < 26; i++){
                        if (node->childs[i]) {
                            qu.push(node->childs[i].get());
                        }
                    }
                }
                else{
                    if(node->childs[ch - 'a']){
                        qu.push(node->childs[ch - 'a'].get());
                    }
                }
            }
        }
        while(!qu.empty()){
            if(qu.front()->valid){
                return true;
            }
            qu.pop();
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
