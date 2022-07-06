class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, -1) && visited.size() == n;
    }
private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    
    bool dfs(int curr_vertex, int prev_vertex){
        if(visited.find(curr_vertex) != visited.end()){
            return false;
        }
        
        visited.insert(curr_vertex);
        
        for(auto dest_vertex: graph[curr_vertex]){
            if(dest_vertex == prev_vertex){
                continue;
            }
            else{
                if(!dfs(dest_vertex, curr_vertex)){
                    return false;
                }
            }
        }
        return true;
    }
};