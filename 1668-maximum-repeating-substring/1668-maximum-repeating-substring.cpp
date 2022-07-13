class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(sequence == word) return true;
        if(word.length() > sequence.length()) return false;

        int wlen = word.length();
        int slen = sequence.length();
        int ans = 0;
        for(int i = 0; i < slen - wlen + 1; i++){
            int j = i;
            int k = 0;
            int curr = 0;
            while(j < slen){
                if(word[k] == sequence[j]){
                    j++;
                    k++;
                }
                else{
                    break;
                }
                if(k == wlen){
                    curr++;
                    k = 0;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};