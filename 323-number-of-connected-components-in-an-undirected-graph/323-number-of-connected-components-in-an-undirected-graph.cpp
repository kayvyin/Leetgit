class Solution {
void dfs(vector<vector<int>>& edges, vector<bool>& visited, unordered_map<int, vector<int>>& graph, int curr_vertex){
    
    visited[curr_vertex] = true;
    for(int dest_vertex: graph[curr_vertex]){
        if(!visited[dest_vertex]){
            dfs(edges, visited, graph, dest_vertex);
        }
    }
}
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, false);
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int num_Components = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                num_Components++;
                dfs(edges, visited, graph, i);
            }
        }
        return num_Components;
    }
};