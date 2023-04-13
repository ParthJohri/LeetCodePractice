class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size()) return false;
        stack<int> s;
        int x=0,n=popped.size();
        for(int i=0;i<n;i++){
            if(pushed[i]==popped[x]){
                x++;
                continue;
            }
            if(!s.empty() and s.top()==popped[x]){
                while(!s.empty() and s.top()==popped[x]){
                    x++;
                    s.pop();
                }
            }
            s.push(pushed[i]);
        }
        while(x<n and !s.empty()){
            if(s.top()==popped[x]){
                s.pop();
                x++;
            }
            else return false;
        }
        return s.empty();
    }
};