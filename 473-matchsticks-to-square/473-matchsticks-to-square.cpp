class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n < 4) return false;
        
        int sum = 0;
        
        for(int match_length : matchsticks){
            sum += match_length;
        }
        
        if(sum % 4 != 0){
            return false;
        }
        
        sort(matchsticks.begin(), matchsticks.end());
        
        vector<int> square(4, 0);
        
        return dfs(matchsticks, square, n - 1, sum / 4);
    }
private:
    bool dfs(vector<int>& matchsticks, vector<int>& square, int idx, int target){
        if(idx == -1){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if((square[i] + matchsticks[idx] > target) || 
                (i > 0 && square[i] == square[i - 1])){
                continue;
            }
            square[i] += matchsticks[idx];
            
            if(dfs(matchsticks, square, idx - 1, target)){
                return true;
            }
            square[i] -= matchsticks[idx];
        }
        return false;
    }
};