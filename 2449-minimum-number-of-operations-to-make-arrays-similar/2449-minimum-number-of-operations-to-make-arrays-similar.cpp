class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> evennums,eventarget,oddnums,oddtarget;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(auto i:nums){
            if(i%2) oddnums.push_back(i);
            else evennums.push_back(i);
        }
        for(auto i:target){
            if(i%2) oddtarget.push_back(i);
            else eventarget.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<evennums.size();i++){
            if(eventarget[i]>evennums[i])
            ans+=(eventarget[i]-evennums[i])/2;
        }
        for(int i=0;i<oddnums.size();i++){
            if(oddtarget[i]>oddnums[i])
            ans+=(oddtarget[i]-oddnums[i])/2;
        }
        return ans;
    }
};