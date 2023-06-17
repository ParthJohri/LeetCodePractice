class Solution {
public:
    int recur(int currIndex,int prevValue,vector<int>&arr1,vector<int>&arr2,vector<unordered_map<int,int>>&m){
        if(arr1.size()==currIndex) return 0;
        if(m[currIndex][prevValue]!=NULL) return m[currIndex][prevValue];
        int res1=INT_MAX;
        if(arr1[currIndex]>prevValue){
            res1=recur(currIndex+1,arr1[currIndex],arr1,arr2,m);
        }
        int res2=INT_MAX;
        int up=upper_bound(arr2.begin(),arr2.end(),prevValue)-arr2.begin();
        if(up==arr2.size()) res2=INT_MAX;
        else res2=recur(currIndex+1,arr2[up],arr1,arr2,m);
        int ans=0;
        if(res2==INT_MAX) ans=res1;
        else ans=min(res1,res2+1);
        return m[currIndex][prevValue]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<unordered_map<int,int>> m(5000);
        sort(arr2.begin(),arr2.end());
        int res=recur(0,-1,arr1,arr2,m);
        if(res==INT_MAX) return -1;
        else return res;
    }
};