class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& grid, vector<vector<char>>& visited, int i, int j){
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || visited[i][j] || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        visited[i][j] = true;
        
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<char>> visited = vector<vector<char>>(m, vector<char>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, visited, i, j);
                }
                             
            }
        }
        return ans;
    }
};