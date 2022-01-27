class Solution {
public:
    int gcd(int a ,int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
        else
            return gcd(b%a,a);
    }
    int findGCD(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        return gcd(mx,mn);
    }
};