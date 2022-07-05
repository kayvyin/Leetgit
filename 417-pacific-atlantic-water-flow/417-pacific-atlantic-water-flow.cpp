class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visiting, vector<vector<bool>> &ref, int i, int j,  int m, int n, int oldheight){
        if(i > m - 1 || i < 0 || j > n - 1 || j < 0 || visiting[i][j] == true || 
                oldheight > heights[i][j]){
            return;
        }
        visiting[i][j] = true;
        if(visiting[i][j] == true && ref[i][j] == true){
            ans.push_back({i, j});
        }
        dfs(heights, visiting, ref, i + 1, j, m, n, heights[i][j]);
        dfs(heights, visiting, ref, i - 1, j, m, n, heights[i][j]);
        dfs(heights, visiting, ref, i , j + 1, m, n, heights[i][j]);
        dfs(heights, visiting, ref, i, j - 1, m, n, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(heights, pacific, atlantic, i, 0, m, n, heights[i][0]);
            dfs(heights, atlantic, pacific, i, n -1, m, n, heights[i][n-1]);
        }
        for(int j = 0; j < n; j++){
            dfs(heights, pacific, atlantic, 0, j, m, n, heights[0][j]);
            dfs(heights, atlantic, pacific, m - 1, j, m, n, heights[m-1][j]);
        }
        return ans;
    }
};