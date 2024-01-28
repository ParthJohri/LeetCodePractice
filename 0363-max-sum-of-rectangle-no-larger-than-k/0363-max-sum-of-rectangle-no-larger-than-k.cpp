class Solution {
public:
    int maxSum(vector<int>&nums,int k){
        set<int> s;
        s.insert(0);
        int ans=INT_MIN,sum=0;
        for(auto i:nums){
            sum+=i;
            auto it=s.lower_bound(sum-k);
            if(it!=s.end()){
                ans=max(ans,sum-*it);
            }
            s.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size(),col=matrix[0].size(),ans=INT_MIN;
        for(int i=0;i<col;i++){
            vector<int>prefix(row,0);
            for(int j=i;j<col;j++){
                for(int temp=0;temp<row;temp++){
                    prefix[temp]+=matrix[temp][j];
                }
                int val=maxSum(prefix,k);
                if(val<=k)
                    ans=max(ans,val);
            }
        }
        for(int i=0;i<row;i++){
            vector<int>prefix(col,0);
            for(int j=i;j<row;j++){
                for(int temp=0;temp<col;temp++){
                    prefix[temp]+=matrix[j][temp];
                }
                int val=maxSum(prefix,k);
                if(val<=k)
                    ans=max(ans,val);
            }
        }
        return ans;
    }
};