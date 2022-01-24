class Solution {
public:
    int mySqrt(int x) {
        int start=1;
        int end=x;
        int mid=0;
        int ans=-1;
        while(start<=end)
        {
            mid= start + (end-start)/2;
            if(mid==x/mid)
                return mid;
            else if(mid>x/mid)
                end=mid-1;
            else
            {
                start=mid+1;
                ans=mid;
            }
        }
        return x==0?0:ans;
    }
};