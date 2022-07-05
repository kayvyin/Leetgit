/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> cloned_cache;
    
    Node* dfs(Node* curr){
        if(cloned_cache.find(curr) != cloned_cache.end()){
            return cloned_cache[curr];
        }
        cloned_cache[curr] = new Node(curr->val);
        for(auto child : curr->neighbors){
            cloned_cache[curr]->neighbors.push_back(dfs(child));
        }
        return cloned_cache[curr];
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        return dfs(node);
    }
};