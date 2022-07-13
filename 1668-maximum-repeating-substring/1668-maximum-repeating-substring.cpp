class Solution {
public:
    int maxRepeating(string s, string w) {
        
        // store original word length
        int wl = w.length();
        int sl = s.length();
        
        // build up word and preprocess LPS
        while(w.size() < sl)w+=w;
        
        vector<int>lps(w.length());
        lps[0] = 0;
        
        int i = 1;
        int j = 0;
        while(i < w.length())
        {
            if(w[i]==w[j])lps[i++]=++j;
            else
            {
                if(j==0)lps[i++]=0;
                else j = lps[j-1];
            }
        }
        
        // run KMP over updated word and sequence string
        i = 0;
        j = 0;
        int maxc = 0;
        while(i < sl)
        {
            if(s[i]==w[j])i++,++j;
            else
            {
                if(j==0)i++;
                else j = lps[j-1];
            }
            

            // word pointer divisible by original word length and so is a repeated substring
            // repeat count => j / word length and track the max repeat
            if((j%wl)==0)
                maxc = max(maxc,j/wl);
        }
        
        // return max repeat count
        return maxc;        
    }
};