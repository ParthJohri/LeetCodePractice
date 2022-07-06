class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int n=v.size(),x=0;
        n=n%2==0?n-2:n-1;
        for(int i=n;i>=0;i-=2)
            nums[i]=v[x++];
        n=v.size();
        n=n%2==0?n-1:n-2;
        for(int i=n;i>=1;i-=2)
            nums[i]=v[x++];
    }
};