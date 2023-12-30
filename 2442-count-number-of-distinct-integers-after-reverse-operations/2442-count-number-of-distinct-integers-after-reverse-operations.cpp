class Solution {
public:
    int reverse(int& n){
        int rev=0;
        while(n!=0){
            rev=rev*10+n%10;
            n/=10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        int ans=0;
        for(auto i:nums){
            s.insert(i);
            int rev=reverse(i);
            s.insert(rev);
        }
        ans=s.size();
        return ans;
    }
};