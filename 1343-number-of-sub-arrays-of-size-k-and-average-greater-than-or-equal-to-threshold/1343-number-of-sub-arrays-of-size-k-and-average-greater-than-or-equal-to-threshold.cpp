class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0,sum=0,avg;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        avg=sum/k;
        if(avg>=threshold) ans++;
        for(int i=k;i<arr.size();i++){
            sum+=arr[i]-arr[i-k];
            avg=sum/k;
            if(avg>=threshold) ++ans;
        }
        return ans;
    }
};