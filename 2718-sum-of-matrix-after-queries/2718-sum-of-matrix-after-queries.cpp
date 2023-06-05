class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans=0,row=n,col=n;
        map<int,int> r,c;
        for(int i=queries.size()-1;i>=0;i--){
            int type=queries[i][0],index=queries[i][1],value=queries[i][2];
            if(type==0){
                if(r.count(index)) continue;
                else{
                    ans+=col*value;
                    r[index]++;
                    row--;
                }
            }
            else if(type==1){
                if(c.count(index)) continue;
                else{
                    ans+=row*value;
                    c[index]++;
                    col--;
                }
            }
        }
        return ans;
    }
};