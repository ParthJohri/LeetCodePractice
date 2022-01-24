class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int start=1,end=num,mid=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mid*mid==num)
                return true;
            else if(mid>num/mid)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
};