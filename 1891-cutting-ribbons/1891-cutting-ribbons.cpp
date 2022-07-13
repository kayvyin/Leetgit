class Solution {
public:
    int valid(vector<int>& ribbons, int k, int len)
    {
        int cuts = 0;
        for(int i = 0 ; i < ribbons.size() ; ++i)
            cuts += ribbons[i] / len;
    
        return cuts >= k ;
    }
    int maxLength(vector<int>& ribbons, int k) {
        int n = ribbons.size(), mx = INT_MIN;
        
        for(int it : ribbons)
            mx = max(mx,it);
        
        int l = 1 , r = mx;
        while(l <= r)
        {
            int mid = l + ( r - l ) / 2;
            if(valid(ribbons, k , mid) )
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return r;
    }
};