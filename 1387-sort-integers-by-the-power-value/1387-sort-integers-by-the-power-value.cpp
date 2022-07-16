
class Solution {
public:
    struct greater_oper{
        bool operator()(pair<int, int> &p1, pair<int, int> &p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            else return p1.first < p2.first;            
        }
    };
    
    #define pis pair<int, int>
    
    int getKth(int lo, int hi, int k) {   
        priority_queue<pis, vector<pis>, greater_oper> max_heap;
        
        for(int curr = lo; curr <= hi; curr++){
            int value = curr, count = 0;
            
            while(value != 1){
                if(value % 2 == 0) value /= 2;
                else value = 3 * value + 1;
                count++;
            }
            
            max_heap.push({count, curr});
            if(max_heap.size() > k) max_heap.pop();
        }
        
        return max_heap.top().second;
    }
};