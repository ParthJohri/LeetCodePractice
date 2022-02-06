class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int start,end,mid,pos=0,count=0;
        for(auto i: grid)
        {
            vector<int> v=i;
            start=0,end=v.size()-1;
            while(start<=end)
            {
                mid=start+(end-start)/2;
                if(v[mid]>=0)
                    start=mid+1;
                else if(v[mid]<0)
                    end=mid-1;
            }
            count+=v.size()-start;
        }
        return count;
    }
};