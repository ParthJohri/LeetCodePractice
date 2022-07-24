class Solution {
public:
    int binarysearch(int l,int h,vector<int> &nums,int x){
        while(l<h){
           int mid=l+(h-l)/2;
           if(nums[mid]>=x)
               h=mid;
            else
               l=mid+1;
        }
        return l;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long count=0,temp=0;
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(temp==nums[i])
                continue;
            else{
                v.push_back(__builtin_popcount(nums[i]));
            }
            temp=nums[i];
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<v.size()){
            count+=v.end()-lower_bound(v.begin(),v.end(),k-v[i]);
            // count+=v.size()-binarysearch(i,nums.size()-1,v,k-v[i]);
            i++;
        }
        return count;
    }
};