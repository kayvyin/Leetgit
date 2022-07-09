class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.length();
        
        vector<bool> dp(len, false);
        
        dp[len] = true;
        
        for(int i = len - 1; i >= 0; i--){
            for(int j = 0; j < wordDict.size(); j++){
                if(i + wordDict[j].length() <= len && s.substr(i, wordDict[j].length()) == wordDict[j]){
                    dp[i] = dp[i + wordDict[j].length()];
                }
                if(dp[i] == true){
                    break;
                }
            }
        }
        return dp[0];
    }
};