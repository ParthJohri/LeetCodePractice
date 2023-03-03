class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candle,ans(queries.size(),0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='|')
                candle.push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0],end=queries[i][1];
            int lb=lower_bound(candle.begin(),candle.end(),start)-candle.begin();
            int ub=upper_bound(candle.begin(),candle.end(),end)-candle.begin()-1;
            if(lb<ub){
                ans[i]=candle[ub]-candle[lb]+1-(ub-lb+1);
            }
        }
        return ans;
    }
};