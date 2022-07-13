class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if(n == 2){
            return min(cost[0], cost[1]);
        }
        
        vector<int> dp(n);
        
        int down1 = 0;
        int down2 = 0;
        
        for(int i = 2; i < n + 1; i++){
            int temp = down1;
            down1 = min(down1 + cost[i - 1], down2 + cost[i - 2]);
            down2 = temp;
        }
        return down1;
    }
};