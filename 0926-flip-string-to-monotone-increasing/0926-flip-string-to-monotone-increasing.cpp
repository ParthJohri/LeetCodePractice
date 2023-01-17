class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0,ans=0;
        for(auto ch:s){
            if(ch=='1') ++ones;
            else{
                // Flip the zero
                ans++;
                // Flip all ones before zero
                ans=min(ans,ones);
            }
        }
        return ans;
    }
};