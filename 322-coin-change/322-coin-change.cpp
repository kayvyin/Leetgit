class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount + 1;
        
        vector<int> dp(n, amount + 1);
        
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){
            for(auto c : coins){
                if(i - c >= 0){
                    dp[i] = min(dp[i],  1 + dp[i - c]);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};