class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int maxi=*max_element(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++) 
            {if(arr[i]==maxi)
                return i;}
        return -1;
    }
};