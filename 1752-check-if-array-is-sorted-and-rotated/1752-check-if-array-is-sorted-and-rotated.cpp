class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int k=nums.size()-1;
        if(v==nums)
            return true;
        while(k--)
        {
            v=rotate(v,1);
            if(v==nums)
            return true;
        }
        return false;
    }
    vector<int> rotate(vector<int> vec,int k)
    {
        k=k%vec.size();
        reverse(vec,0,vec.size()-1);
        reverse(vec,0,k-1);
        reverse(vec,k,vec.size()-1);
        return vec;
    }
    void reverse(vector<int> &v,int start, int end)
    {
        while(start<end)
        {
             int temp=v[start];
            v[start]=v[end];
            v[end]=temp;
            start++;
            end--;
        }
    }
};