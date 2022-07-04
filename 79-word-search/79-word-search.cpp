class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(idx == word.length()) return true;
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] != word[idx] || visited[i][j]){
            return false;
        }
        visited[i][j] = true;
        bool res = dfs(board, word, idx + 1, i + 1, j) ||
                    dfs(board, word, idx + 1, i - 1, j) ||
                    dfs(board, word, idx + 1, i, j + 1) || 
                    dfs(board, word, idx + 1, i, j - 1);

        visited[i][j] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};