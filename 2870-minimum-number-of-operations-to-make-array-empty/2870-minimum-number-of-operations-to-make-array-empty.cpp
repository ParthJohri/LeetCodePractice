class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums) m[i]++;
        int ans=0;
        for(auto i:m){
            int x=i.second;
            if(x==1) return -1;
            ans+=x/3;
            x%=3;
            if(x==1) ans++;
            if(x%2==0) ans+=x/2;
        }
        return ans;
    }
};