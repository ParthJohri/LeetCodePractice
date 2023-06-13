class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int increasing=0,decreasing=0,i=1,n=arr.size(),ans=0;
        while(i<n){
            increasing=0;
            decreasing=0;
            while(i<n and arr[i]>arr[i-1]) increasing++,i++;
            while(i<n and arr[i]<arr[i-1]) decreasing++,i++;
            if(increasing>0 and decreasing>0) ans=max(ans,increasing+decreasing+1);
            else if(!increasing and !decreasing) i++;
        }
        return ans;
    }
};