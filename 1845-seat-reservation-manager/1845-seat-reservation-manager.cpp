class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            p.push(i);
        }
    }
    int reserve() {
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