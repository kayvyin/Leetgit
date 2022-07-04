class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
public:
    MedianFinder() {
            
    }
    
    void addNum(int num) {
        if(min_heap.empty() || num < min_heap.top()){
            max_heap.push(num);
            if(max_heap.size() - min_heap.size() > 1){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        else{
            min_heap.push(num);
            if(min_heap.size() - max_heap.size() > 1){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
            
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
        return min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
    }
};
/*
1,2,6,6,4 1, 2,3,6
max_heap:
1, 1, 2, 
min_heap:
6, 6, 4,
*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */