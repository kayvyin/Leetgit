class Solution {
private:
    int m, n;
    set<pair<int,int>> visited;
    void dfs(vector<vector<char>>& board, int i, int j, int control){
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || 
            board[i][j] != 'O' || visited.count(make_pair(i, j))){
            return;
        }
        if(control == 0){
            visited.insert(make_pair(i, j));
        }
        if(control == 1){
            board[i][j] = 'X';
        }
        
        dfs(board, i + 1, j, control);
        dfs(board, i - 1, j, control);
        dfs(board, i, j + 1, control);
        dfs(board, i, j - 1, control);
        
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < m; i++){
            dfs(board, i, 0, 0);
            dfs(board, i, n - 1, 0);
        }
        
        for(int j = 0; j < n; j++){
            dfs(board, 0, j, 0);
            dfs(board, m - 1, j, 0);
        }
        
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O'){
                    dfs(board, i, j, 1);
                }
            }
        }
        
    }
};