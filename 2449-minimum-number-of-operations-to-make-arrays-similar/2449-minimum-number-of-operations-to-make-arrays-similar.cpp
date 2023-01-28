class Solution {
public:
    long long makeSimilar(vector<int>& num, vector<int>& t) {
        vector<int> nums,target,nums2,target2;
        for(auto i:num){
            if(i%2) nums.push_back(i);
            else nums2.push_back(i);
        }
        for(auto i:t){
            if(i%2) target.push_back(i);
            else target2.push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        sort(nums2.begin(),nums2.end());
        sort(target2.begin(),target2.end());
        long long ans=0,ans2=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(target[i]-nums[i])/2;
        }
        for(int i=0;i<nums2.size();i++){
            ans2+=abs(target2[i]-nums2[i])/2;
        }
        return (ans+ans2)/2;
    }
};