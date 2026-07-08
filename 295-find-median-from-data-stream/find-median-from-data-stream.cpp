class MedianFinder {
public:
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int,vector<int>> maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;  // critical ...for the first time ..dont check the below conditions
        }

        if(num>=maxHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        else if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
       
        
    }
    
    double findMedian() {
        int n=minHeap.size()+maxHeap.size();
        if (n == 0) return 0.0;

        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;
        
    }
        
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */