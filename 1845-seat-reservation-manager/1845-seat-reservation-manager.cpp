class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int count;
    SeatManager(int n) {
        count=1;
    }
    int reserve() {
        if(p.size()==0) return count++;
        int t=p.top();
        p.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        p.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */