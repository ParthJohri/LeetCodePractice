class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(high-low+1);
        if(ans%2==0) return ans/2;
        else{
            ans/=2;
            ans--;
            if(low%2!=0 and high%2!=0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};