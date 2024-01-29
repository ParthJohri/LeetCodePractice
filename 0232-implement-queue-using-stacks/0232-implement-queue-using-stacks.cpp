class MyQueue {
public:
    //  https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=6
    //  Do you know when we should use two stacks to implement a queue?

    // I was asked in the internship interview of a company two years ago.

    // The application for this implementation is to separate read & write of a queue in multi-processing. One of the stack is for read, and another is for write. They only interfere each other when the former one is full or latter is empty. 

    //  When there's only one thread doing the read/write operation to the stack, there will always one stack empty. However, in a multi-thread application, if we have only one queue, for thread-safety, either read or write will lock the whole queue. In the two stack implementation, as long as the second stack is not empty, push operation will not lock the stack for pop.

    stack<int> input,output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int t=output.top();
        output.pop();
        return t;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() and output.empty();
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