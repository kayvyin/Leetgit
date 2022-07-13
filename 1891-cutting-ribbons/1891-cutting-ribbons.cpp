class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int shortest = 1;
        int longest = INT_MIN;
        
        for(int n : ribbons){
            longest = max(longest, n);
        }
        int num_ribbons;
        while(shortest <= longest){
            int guess = shortest + (longest - shortest) / 2;
            num_ribbons = 0;
            for(int n : ribbons){
                num_ribbons += n / guess;
            }
            if(num_ribbons >= k){
                shortest = guess + 1;
            }
            else{
                longest = guess - 1;
            }
        }
        return longest;
    }
};