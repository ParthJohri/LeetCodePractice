class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(),start=0,end=n-1,ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid] > arr[mid+1]){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};