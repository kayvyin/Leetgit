class TrieNode {
    public:
    bool isLeaf;
    TrieNode* t[26];
    TrieNode() {
        isLeaf=false;
        for(int i=0;i<26;i++) t[i]=NULL;
    }
};

class Trie {
    TrieNode* root;
    public:
    
    TrieNode* getRoot(){return root;}
    void addwords(string& s) {
        TrieNode* cur = root;
        for(char c : s) {
            if(cur->t[c-'a']!=NULL) cur=cur->t[c-'a'];
            else {
                cur->t[c-'a'] = new TrieNode();
                cur=cur->t[c-'a'];
            }
        }
        cur->isLeaf=true;
    }
    
    Trie(vector<string>& words) {
        root = new TrieNode();
        for(string s : words) {
            addwords(s);
        }
    }

};


class Solution {
public:
    int a[5] = {-1,0,1,0,-1};
    
    
    bool check(int i, int j,int m, int n, vector<vector<char>>& b) {
        if(i<0 || i>=m || j<0 || j>=n || b[i][j]==' ') return false;
        return true;
    }
    
    void solve(int i, int j,vector<vector<char>>& b, string& word, TrieNode* root, unordered_set<string>&res) {
        int m=b.size(), n=b[0].size(),l,r;
        char c = b[i][j];
        if(root->t[c-'a']) {
            word.push_back(c);
            root=root->t[c-'a'];
            if(root->isLeaf) res.insert(word);
            b[i][j]=' ';
            for(int k=0;k<4;k++) {
                l = i+a[k];
                r = j+a[k+1];
                if(check(l,r,m,n,b)) solve(l,r,b,word,root,res);
            }
            b[i][j]=c;
            word.pop_back();
        }
    }
    
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        
        unordered_set<string>res;
        
        for(int i=0;i<b.size();i++) {
            for(int j=0;j<b[0].size();j++) {
                string word = "";
                solve(i,j,b,word,root,res);
            }
        }
        
        vector<string>ans;
        
        for(string s : res) ans.push_back(s);
        
        return ans;
    }
};