class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        int j=0;
      
       for(int i=0;i<=2;i++)
       {
           while(v[i]>0)
          { nums[j]=i;
          v[i]--;
          j++;}
       }
        cout<<"[";
        for(int x:nums)
            cout<<x<<",";
        cout<<"]";
    }
};