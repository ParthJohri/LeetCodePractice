class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty() and temperatures[s.top()]<=temperatures[i]){
                    s.pop();
                }
                if(!s.empty())
                    ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};