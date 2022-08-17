class MinStack {
public:
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> mn;
    MinStack() {
        vector<int> a;
        v=a;
    }
    
    void push(int val) {
        v.push_back(val);
        mn.push(val);
    }
    
    void pop() {
        int num=v.back();
        v.pop_back();
        while(!mn.empty()){
            mn.pop();
        }
        for(auto i:v){
            mn.push(i);
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */