class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegrees(numCourses, 0);
        
        for(auto edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
            inDegrees[edge[0]]++;
        }
        queue<int> sources;
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0){
                sources.push(i);
            }
        }
        vector<int> sorted;
        while(!sources.empty()){
            int popped = sources.front();
            sources.pop();
            sorted.push_back(popped);
            for(auto out_vertex : graph[popped]){
                if(--inDegrees[out_vertex] == 0){
                    sources.push(out_vertex);
                }
            }
        }
        if(sorted.size() == numCourses){
            return true;
        }
        return false;
    }
};
