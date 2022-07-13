class Solution {
public:
    int maxRepeating(string s, string w) {
        
        // store original word length
        int wl = w.length();
        int sl = s.length();
        
        string w2 = w;
        // build up word and preprocess LPS
        while(w2.size() < sl)w2+=w;
        
        vector<int>lps(w2.length(), 0);
        lps[0] = 0;
        
        int i = 1;
        int prev_lps = 0;
        while(i < w2.length()){
            if(w2[i] == w2[prev_lps]){
                lps[i++] = ++prev_lps;
            }
            else{
                if(prev_lps == 0){
                    prev_lps = 0;
                    i++;
                }
                else{
                    prev_lps = lps[prev_lps - 1]; 
                }
            }
        }
        
        i = 0;
        prev_lps = 0;
        
        int ans = 0;
        
        while(i < sl){
            if(s[i] == w2[prev_lps]){
                i++;
                prev_lps++;
            } 
            else{
                if(prev_lps == 0){
                    i++;
                }
                else{
                    prev_lps = lps[prev_lps - 1];
                }
            }
            if(prev_lps % wl == 0){
                ans = max(ans, prev_lps / wl);
            }
        }
        return ans;
        
    }
};