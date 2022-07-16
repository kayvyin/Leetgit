class Solution {
    vector<int>dp=vector<int>(1000000);
    int util(int x) {
        if(x<2) return dp[x];
        return dp[x]?dp[x]:dp[x]=1+(x&1?util(3*x+1):util(x/2));
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> t;
        for(int i=lo; i<=hi; i++)
            t.push_back({util(i),i});
        sort(t.begin(),t.end());
        return t[k-1].second;
    }
};