class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int k=3,sum=0,tsum=0;
        for(auto i:arr)
            sum+=i;
        while(k<=arr.size())
        {
            for(int i=0;i<k;i++)
            {
                tsum+=arr[i];
            }
            sum+=tsum;
            for(int i=k;i<arr.size();i++)
            {
                tsum+=arr[i]-arr[i-k];
                sum+=tsum;
            }
            k+=2;
            tsum=0;
        }
        return sum;
    }
};