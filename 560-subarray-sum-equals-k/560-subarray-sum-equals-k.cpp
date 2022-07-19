class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Time Complexity : O(N)
        int sum=0,count=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(m.count(sum-k)){   
                count+=m[sum-k];
            }
            m[sum]++;
        }
        return count;
        // O(N2) Solution
        // vector<int> pr(nums.size(),1);
        // pr[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     pr[i]=pr[i-1]+nums[i];
        // }
        // int count=0,sum=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         if(i!=0){
        //             sum=pr[j]-pr[i-1];
        //         }
        //         else
        //             sum=pr[j];
        //         if(sum==k)
        //             ++count;
        //     }
        // }
    }
};