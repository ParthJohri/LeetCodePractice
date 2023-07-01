class Solution {
public:
    int mn=INT_MAX;
    void recur(vector<int>&cookies,vector<int>&cook,int index){
        if(index==cookies.size()) {
            int ans=INT_MIN;
            for(auto i:cook){
                ans=max(ans,i);
            }
            mn=min(mn,ans);
            return ;
        }
        for(int i=0;i<cook.size();i++){
            cook[i]+=cookies[index];
            recur(cookies,cook,index+1);
            cook[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> cook(k,0);
        recur(cookies,cook,0);
        return mn;
    }
};