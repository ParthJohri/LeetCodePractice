class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> s;
    unordered_map<int,int> m;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            {s.push(i);m[i]++;}
    }
    
    int popSmallest() {
        int p=s.top();
        s.pop();
        m[p]--;
        return p;
    }
    
    void addBack(int num) {
        if(m[num]==0) {s.push(num);m[num]++;}
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */