class Solution {
public:
    long long makeSimilar(vector<int>& num, vector<int>& t) {
        vector<int> nums,target,nums2,target2;
        sort(num.begin(),num.end());
        sort(t.begin(),t.end());
        for(auto i:num){
            if(i%2) nums.push_back(i);
            else nums2.push_back(i);
        }
        for(auto i:t){
            if(i%2) target.push_back(i);
            else target2.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(target[i]>nums[i])
            ans+=(target[i]-nums[i])/2;
        }
        for(int i=0;i<nums2.size();i++){
            if(target2[i]>nums2[i])
            ans+=(target2[i]-nums2[i])/2;
        }
        return ans;
    }
};