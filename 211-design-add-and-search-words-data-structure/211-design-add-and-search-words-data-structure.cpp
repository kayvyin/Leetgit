struct TrieNode{
    bool isEnd = false;
    TrieNode *children[26];
};
class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr_node = root;
        
        for(auto c : word){
            if(!curr_node->children[c - 'a']){
                curr_node->children[c - 'a']  = new TrieNode();
            }
            curr_node = curr_node->children[c - 'a'];
        }
        curr_node->isEnd = true;
        
    }
    bool dfs(TrieNode* curr_node, string word, int idx){
        for(int i = idx; i < word.length(); i++){
            if(word[i] == '.'){
                for(auto child : curr_node->children){
                    if(child && dfs(child, word, i + 1)){
                        return true;
                    }
                }
                return false;
            }
            if(!curr_node->children[word[i] - 'a']){
                    return false;
                }
                curr_node = curr_node->children[word[i] - 'a'];
            }
        
        return curr_node->isEnd;
    }
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */