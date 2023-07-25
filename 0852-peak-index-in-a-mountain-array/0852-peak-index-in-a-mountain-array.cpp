class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        int mid=0;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]>arr[mid+1])
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};