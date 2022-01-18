class Solution {
public:
    int binarySearch(vector<int> arr, int target)
    {
        int start=0;
        int end=arr.size()-1;
        int mid=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==target)
                return mid;
            else if(target>arr[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        int found=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            found=binarySearch(arr,2*arr[i]);
            if(found!=-1&&found!=i)
                return true;
        }
        return false;
    }
};