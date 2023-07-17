class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        // 1 2 3 4 5 6 7 8 
        // maxHeap stores left half elements in descending order 
        // minHeap stores right half elements in ascending order
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        // maxHeap size or minHeap both could get +1 extra size it is our choice
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int leftHalfSize=maxHeap.size(),rightHalfSize=minHeap.size();
        if((leftHalfSize+rightHalfSize)%2==0){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */