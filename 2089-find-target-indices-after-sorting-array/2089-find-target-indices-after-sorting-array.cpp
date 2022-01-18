class Solution {
public:
    int binarySearch(vector<int> nums, int target,bool b)
    {   int start=0;
        int end=nums.size()-1;
        int mid=0;
        int found=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            {if(b)
             end=mid-1;
            else 
                start=mid+1;
             found=mid;
           }
            else if(target>nums[mid])
                start=mid+1;
            else
                end=mid-1;}
     return found;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
       
        sort(nums.begin(),nums.end());
        vector<int> n;
        vector<int> n1;
        int ini,eni;
        ini=binarySearch(nums,target,true);
        eni=binarySearch(nums,target,false);
        for(int i=ini;i<=eni;i++)
            n.push_back(i);
        return (ini==-1&&eni==-1)?n1:n;
    }
};