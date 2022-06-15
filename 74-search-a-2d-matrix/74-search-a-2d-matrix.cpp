class Solution {
public:
    bool bs(vector<int> v,int target)
    {
        int start=0,end=v.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(v[mid]==target) return true;
            else if(v[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i:matrix)
        {
            if(target>i[i.size()-1])
                continue;
            else
                return bs(i,target);
        }
        return false;
    }
};