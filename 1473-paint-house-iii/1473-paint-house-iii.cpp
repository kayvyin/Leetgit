class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = cost.size();
        this->n = cost[0].size();
        
        if(target > m){
             return -1;
        }
        
        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        
        int ans = dfs(houses, cost, 0, 0, 0, target);
        
        return ans == INT_MAX / 2 ? -1 : ans;
        
        
    }
private:
    int m, n;
    
    vector<vector<vector<int>>> dp;
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int prev_Color, int k, int target){
        if(i == m){
            if(k == target) return 0;
            
            else return INT_MAX / 2;
        }
        if(k > target) return INT_MAX / 2;
        
        if(dp[i][prev_Color][k] != -1) return dp[i][prev_Color][k];
        
        int ans = INT_MAX / 2;
        
        if(houses[i] == 0){
            for(int color = 0; color < n; color++){
                ans = min(ans, cost[i][color] + dfs(houses, cost, i + 1, color + 1, color + 1 == prev_Color ? k : k + 1, target));
                      
            }
        }
        else ans = dfs(houses, cost, i + 1, houses[i], houses[i] == prev_Color ? k : k + 1, target);
        
        return dp[i][prev_Color][k] = ans;
    }
};