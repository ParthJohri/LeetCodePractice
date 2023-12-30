class Solution {
public:
    bool isPalindrome(int num){
        string s=to_string(num);
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    vector<int> choice(int num){
        // Palindrome Number larger than num
        int lar=0,sm=0;
        for(int i=num+1;;i++){
            if(isPalindrome(i)){
                lar=i;
                break;
            }
        }
        for(int i=num;i>=0;i--){
            if(isPalindrome(i)){
                sm=i;
                break;
            }
        }
        // Palindrome Number smaller than num
        return {sm,lar};
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median=nums[n/2];
        long long ans=LONG_MAX;
        vector<int> choices=choice(median);
        for(auto i:choices){
            long long cost=0;
            for(auto j:nums){
                cost+=abs(j-i);
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};