class Solution {
public:
    int k,ans=0;
    int dp[51][51][101];
    int mod=1e9+7;
    int search(vector<int>&v){
        int mx=-1,mx_i=-1,cost=0,n=v.size();
        for(int i=0;i<n;i++){
            if(mx<v[i]){
                mx=v[i];
                mx_i=i;
                cost=cost+1;
            }
        }
        return cost;
    }
    int recur(int n,int index,int m,int k,int mx){
        if(k<0 or index>n) return 0;
        if(mx!=-1 and dp[index][k][mx]!=-1) return dp[index][k][mx];
        if(index==n and k==0){
            // print(temp);
            ++ans;
            return 1;
        }
        int count=0;
        for(int i=1;i<=m;i++){
            // temp.push_back(i);
            if(mx<i)
                count=count%mod+(recur(n,index+1,m,k-1,i)%mod);
            else
                count=count%mod+(recur(n,index+1,m,k,mx)%mod);
            // temp.pop_back();
        }
        return mx!=-1?dp[index][k][mx]=count%mod:count%mod;
    }
    void print(vector<int>&v){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int numOfArrays(int n, int m, int k) {
        this->k=k;
        memset(dp,-1,sizeof(dp));
        // vector<int> temp;
        return recur(n,0,m,k,-1);
        return ans;
    }
};