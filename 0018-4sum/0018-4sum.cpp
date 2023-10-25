class Solution {
public:
    vector<vector<int>> Ksum(vector<int>&nums,long long int target,int k,int index){
        vector<vector<int>> ans;
        if(index>=nums.size()) return ans;
        if(k==2){
            cout<<"IN"<<endl;
            int i=index,j=nums.size()-1;
            while(i<j){
                if(target*1ll-nums[i]*1ll==nums[j]*1ll){
                    ans.push_back({nums[i],nums[j]});
                    while(i<j and nums[i]==nums[i+1]) i++;
                    while(i<j and nums[j]==nums[j-1]) j--;
                    i++;
                    j--;
                }
                else if(target*1ll-nums[i]*1ll>nums[j]*1ll) i++;
                else j--;
            }
        }
        else{
            cout<<"OUT"<<endl;
            int x=nums.size()-k+1;
            for(int i=index;i<x;i++){
                vector<vector<int>> temp=Ksum(nums,target*1ll-nums[i]*1ll,k-1,i+1);
                if(temp.size()>0){
                    for(auto arr:temp){
                        arr.push_back(nums[i]);
                        ans.push_back(arr);
                    }
                }
                while(i<nums.size()-1 and nums[i]==nums[i+1]) i++;
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return Ksum(nums,target,4,0);
    }
};