class Solution {
private:
    vector<vector<bool>> visited;
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || visited[i][j] || grid[i][j] == 0){
            return 0;
        }
        visited[i][j] = true;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + 
                    dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n , 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
};