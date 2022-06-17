class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // Video Solution:- https://www.youtube.com/watch?v=WGm4Kj3lhRI&ab_channel=AlexanderLe
        vector<int> v(temp.size(),0);
        stack<pair<int,int>>s;
        int count=0;
        for(int i=temp.size()-1;i>=0;i--)
        {
            while(!s.empty())
            {
                if(s.top().first>temp[i])
                {
                    v[i]=s.top().second-i; 
                    break;
                }
                else
                    s.pop();
            }
            s.push({temp[i],i});
        }
        return v;
    }
};