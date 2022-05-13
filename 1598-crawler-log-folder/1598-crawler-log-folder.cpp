class Solution {
public:
    int minOperations(vector<string>& logs) {
       stack<string> s;
       for(auto i:logs)
       {
           s.push(i);
           if(i=="../")
           {
               if(!s.empty())
               {
                   s.pop();
                   if(!s.empty())
                   s.pop();
               }
           }
           else if(i=="./")
           {
               if(!s.empty())
                   s.pop();
           }
       }
       return s.size();
    }
};