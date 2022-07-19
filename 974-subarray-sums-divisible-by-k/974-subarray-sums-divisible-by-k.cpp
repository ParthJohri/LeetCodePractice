class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,count=0;
        unordered_map<int,int> m;
        // O(N2) Solution
        // vector<int> pr(nums.size(),0);
        // pr[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     pr[i]=pr[i-1]+nums[i];
        // }
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         if(i!=0){
        //             if(k==0){
        //                 if(pr[j]-pr[i-1]==0) ++count;
        //             }
        //             else{
        //                 if((pr[j]-pr[i-1])%k==0) ++count;
        //             }
        //         }
        //         else{
        //             if(k==0){
        //                 if(pr[j]==0) ++count;
        //             }
        //             else{
        //                 if((pr[j])%k==0) ++count;
        //             }
        //         }
        //     }
        // }
        m[0]=1;
        for(auto i:nums){
            sum+=i;
            int rem=sum%k;
            if(rem<0) rem+=k;
            // if we get -negative remainder then to convert it into positive we need to add k with which we are dividing
            if(m.count(rem)){
                count+=m[rem];
            }
            m[rem]++;
        }
        return count;
    }
};