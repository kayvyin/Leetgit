class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> sources;
        
        int m = rooms.size();
        int n = rooms[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    sources.push(make_pair(i, j));
                }
            }
        }
        vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!sources.empty()){
            int level_size = sources.size();
            
            for(int x = 0; x < level_size; x++){
                auto popped = sources.front();
                sources.pop();
                int i = popped.first;
                int j = popped.second;
                for(auto d: dir){
                    int a = i + d[0];
                    int b = j + d[1];
                    if(a < 0 || a > m - 1 || b < 0 || b > n -1 || rooms[a][b] != INT_MAX){
                        continue;
                    }
                    else{
                        rooms[a][b] = rooms[i][j] + 1;
                        sources.push(make_pair(a, b));
                    }
                }
            }
        }
    }
};