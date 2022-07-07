class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> m;
        
        for(int i = 0; i < s.length(); i++){
            m[s[i]] = i;
        }
        vector<int> ans;
        int curr_end = 0;
        int traversed = 0;
        for(int i = 0; i< s.length(); i++){
            curr_end = max(curr_end, m[s[i]]);
            if(curr_end == i){
                if(ans.size() == 0){
                    ans.push_back(curr_end + 1);
                }
                else{
                    ans.push_back(curr_end - traversed);   
                }
                traversed += curr_end - traversed;
            }
        }
        return ans;
    }
};