class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> s;
        int x=0;
        if(pushed.size()==popped.size()&&pushed.size()==1)
            return pushed[0]==popped[0];
        for(auto i:pushed)
        {
           if(!s.empty())
           { while(s.top()==popped[x])
              {
               s.pop();
               x++;
               if(s.empty())
            break;
                }
           }
            if(i!=popped[x])
                s.push(i);
            else
            {
                x++;
            }
        }
        while(x<popped.size())
        {
            if(s.top()==popped[x++])
                s.pop();
        }
        return s.empty();
    }
};