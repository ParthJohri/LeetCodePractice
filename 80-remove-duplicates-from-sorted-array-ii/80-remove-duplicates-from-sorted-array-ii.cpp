class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        int x=0;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>2){
                nums[x++]=i.first;
                nums[x++]=i.first;
            }
            else{
                int y=i.second;
                while(y--){
                    nums[x++]=i.first;
                }
            }
        }
        return x;
    }
};