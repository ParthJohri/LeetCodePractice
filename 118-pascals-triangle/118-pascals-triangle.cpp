class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v1={1};
        vector<int> v2={1,1};
        ans.push_back(v1);
        if(numRows==1)
            return ans;
        ans.push_back(v2);
        if(numRows==2)
            return ans;
        for(int i=2;i<numRows;i++)
        {
           vector<int> v;
           vector<int> prev=ans[i-1];
           v.push_back(prev[0]);
           int x=0,y=1;
           for(int j=1;j<i;j++)
           {
               int sum=0;
               if(y<prev.size())
               sum+=prev[x]+prev[y];
               x=y;
               y++;
               v.push_back(sum);
           }
           v.push_back(prev[prev.size()-1]);
           ans.push_back(v);
        }
        return ans;
    }
};