class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int res_start = 0;
        int res_len = 0;
        
        
        for(int i = 0; i < s.length(); i++){
            int left = i, right = i;
            
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if(right - left + 1 > res_len){
                    res_start = left;
                    res_len = right - left + 1;
                }
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if(right - left + 1 > res_len){
                    res_start = left;
                    res_len = right - left + 1;
                }
                left--;
                right++;
            }
            
        }
        return s.substr(res_start, res_len);
    }
       
};