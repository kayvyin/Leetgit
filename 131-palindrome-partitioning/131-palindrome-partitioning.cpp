class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(ans, s, 0, curr);
        return ans;
    }
    
    void dfs(vector<vector<string>>& result, string &s, int start, vector<string> &curr){
        if(start >= s.length()){
            result.push_back(curr);
        }
        
        for(int end = start; end < s.length(); end++){
            if(isPali(s, start, end)){
                curr.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPali(string &s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
};