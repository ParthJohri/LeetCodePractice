class Solution {
public:
    int dp[100001];
    int search(vector<vector<int>>&v,int index){
        int s=index,e=v.size()-1,starttime=v[index][1],endtime=v[index][2],ans=v.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            int st=v[mid][1];
            int et=v[mid][2];
            if(starttime>=et){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
    int recur(int index,vector<vector<int>>&v){
        if(index>=v.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int id=search(v,index);
        int choice1=v[index][0]+recur(id,v);
        int choice2=recur(index+1,v);
        return dp[index]=max(choice1,choice2);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // 3-10 100  
        // 6-9 60
        // 4-6 70
        // 2-5 20
        // 1-3 20
        vector<vector<int>> v;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<startTime.size();i++){
            v.push_back({profit[i],startTime[i],endTime[i]});
        }
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            if(a[2]==b[2])
                return a[0]>b[0];
            return a[2]>b[2];
        });
        int ans = recur(0,v);
        return ans;
    }
};