class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(auto stone : stones){
            max_heap.push(stone);
        }
        
        while(max_heap.size() > 1){
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();
            max_heap.push(abs(first - second));
        }
        return max_heap.top();
    }
};