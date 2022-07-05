class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh_oranges = 0;
        queue<pair<int,int>> sources;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fresh_oranges++;
                }
                else if(grid[i][j] == 2){
                    sources.push(make_pair(i, j));
                }
            }
        }
        sources.push(make_pair(-1, -1)); // Separate past round from curr
        
        vector<vector<int>> dir = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int curr_time = -1;
        while(!sources.empty()){
            auto popped = sources.front();
            int i = popped.first;
            int j = popped.second;
            sources.pop();
            if(i == -1){
                curr_time++;
                if(!sources.empty()){
                    sources.push(make_pair(-1, -1));
                }
            }
            for(auto d: dir){
                int a = i + d[0];
                int b = j + d[1];
                if(a < 0 || a > m - 1 || b < 0 || b > n - 1){
                    continue;
                }
                else if(grid[a][b] == 1){
                    grid[a][b] = 2;
                    sources.push(make_pair(a,b));
                    fresh_oranges--;
                }
            }
            
        }
        return fresh_oranges == 0 ? curr_time : -1;
        
    }
};