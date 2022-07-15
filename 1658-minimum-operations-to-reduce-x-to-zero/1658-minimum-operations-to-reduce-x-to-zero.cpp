class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       // 1 2 6 8 11 
       // 11 10 9 5 3
       //      3  5 25 26 27 30
       //     30 27 25  5  4  3 
       vector<int> prf(nums.size());
        vector<int> suf(nums.size());
        prf[0]=nums[0];
        suf[0]=nums[nums.size()-1];
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum<x) return -1;
        int ans=-1,prfmn=INT_MAX,sufmn=INT_MAX,prsu=INT_MAX,supf=INT_MAX;
        if(prf[0]==x)
                prfmn=1;
        if(suf[0]==x)
                sufmn=1;
        for(int i=1;i<nums.size();i++){
            prf[i]+=nums[i]+prf[i-1];
            if(prf[i]==x)
                {prfmn=min(prfmn,i+1); break;}
            suf[i]+=nums[nums.size()-i-1]+suf[i-1];
            if(suf[i]==x)
                {sufmn=min(sufmn,i+1); break;}
        }
        unordered_map<int,int> m,n;
        for(int i=0;i<nums.size();i++){
            m[suf[i]]=i;
            n[prf[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(m.count(x-prf[i])){
                prsu=min(prsu,i+1+m[x-prf[i]]+1);
            }
            else if(n.count(x-suf[i])){
                supf=min(supf,i+1+n[x-suf[i]]+1);
            }
        }
        ans=min(supf,min(prsu,min(prfmn,sufmn)));
        return ans==INT_MAX?-1:ans;
    }
};