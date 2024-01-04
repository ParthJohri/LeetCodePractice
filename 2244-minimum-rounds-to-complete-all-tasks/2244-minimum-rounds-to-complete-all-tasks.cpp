class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        map<int,int> m;
        for(auto i:tasks) m[i]++;
        for(auto &[key,val]:m){
            if(val==1) return -1;
            ans+=val/3;
            val%=3;
            if(val==1) ans++;
            if(val%2==0) ans+=val/2;
        }
        return ans;
    }
};