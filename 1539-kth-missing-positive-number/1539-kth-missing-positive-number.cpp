class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1,x=0;
        while(k--){
            while(x<arr.size() and arr[x]==i) {i++; x++;}
            i++;
        }
        return i-1;
    }
};