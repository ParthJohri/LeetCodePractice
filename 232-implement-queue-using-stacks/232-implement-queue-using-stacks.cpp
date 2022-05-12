class MyQueue {
public:
    stack<int> s1,s2;
//  Do you know when we should use two stacks to implement a queue?

// I was asked in the internship interview of a company two years ago.

// The application for this implementation is to separate read & write of a queue in multi-processing. One of the stack is for read, and another is for write. They only interfere each other when the former one is full or latter is empty. 

//  When there's only one thread doing the read/write operation to the stack, there will always one stack empty. However, in a multi-thread application, if we have only one queue, for thread-safety, either read or write will lock the whole queue. In the two stack implementation, as long as the second stack is not empty, push operation will not lock the stack for pop.

    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.empty()==false)
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int  a=s1.top();
        s1.pop();
        return a;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */