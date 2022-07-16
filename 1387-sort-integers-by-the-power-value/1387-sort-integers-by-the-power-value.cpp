
typedef pair<int,int> p;
class Solution {
public:
    int dp[1000000];
    int dfs(int n){
        if(n==1) 
			return 1; 
        if(dp[n]) 
			return dp[n]; // if already computed
        if(n&1) 
			return dp[n] = 1+dfs(3*n+1); // if odd
        return dp[n] = 1+dfs(n/2); // if even
    }
    int getKth(int l, int h, int k) {
        priority_queue<p,vector<p>,greater<p>>q; // min heap of pairs
        for(int i=l;i<=h;i++)
            q.push({dfs(i),i}); // sort by power of the integer, if power equal then sort by it's value
        int ans;
        while(k--){
            ans=q.top().second; 
            q.pop();
        }
        return ans;
    }
};