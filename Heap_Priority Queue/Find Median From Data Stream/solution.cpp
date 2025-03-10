class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxHeap.empty()||num<maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        // Balance to heap
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()){
            return maxHeap.top();
        }
        else{
            return (maxHeap.top()+minHeap.top())/2.0;
        }
    }
private:
    // put median to minimum
    priority_queue<int> maxHeap;
    
    // put median to maximum
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */