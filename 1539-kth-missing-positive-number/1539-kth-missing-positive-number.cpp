class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left=0,right=arr.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]-mid<=k){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left+k;
    }
};