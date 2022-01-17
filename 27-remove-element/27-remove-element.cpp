class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int num,l=nums.size(),k=0;
        vector<int> p;
        for(int i=0;i<l;i++)
        {
         num=nums[i];
            if(num!=val)
                {p.push_back(num);
                 ++k;}
        }
     for(int i=0;i<k;i++)
         nums[i]=p[i];
           return k;}
};