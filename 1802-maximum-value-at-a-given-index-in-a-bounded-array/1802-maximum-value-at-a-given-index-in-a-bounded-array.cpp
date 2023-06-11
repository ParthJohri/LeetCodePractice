class Solution {
public:
    
    long long calc(long n) 
    {
        return ((n * 1ll* (n + 1)) / 2);
    }
    long long findSum(int totalLen, int val)
    {
        long totalSum = 0;
        int decreasingLen = val; //count of decreasing elements [val, val - 1, .., 1]
        
        //[val, val - 1, val - 2, ... 1, 1, 1, 1]
        if (totalLen >= decreasingLen)
        {
            long long currSum = calc(val);
            int remainingSum = totalLen - decreasingLen; //all 1's
            totalSum = currSum + remainingSum;
        }
        else //[val, val - 1, val - 2]
        {
            long long lastVal = decreasingLen - totalLen;
            totalSum = calc(val) - calc(lastVal);
        }
        return totalSum; 
    }
    int maxValue(int n, int index, int maxSum) {
        int start=1,end=maxSum,ans=1,leftcount=index,rightcount=n-index-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long leftSum=findSum(leftcount,mid-1);
            long long rightSum=findSum(rightcount,mid-1);
            long long totalSum=leftSum+rightSum+mid;
            if(totalSum<=maxSum){
                ans=mid;
                start=mid+1;
            }
            else 
                end=mid-1;
        }
        return ans;
    }
};