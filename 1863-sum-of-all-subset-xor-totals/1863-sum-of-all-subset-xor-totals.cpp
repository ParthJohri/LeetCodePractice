class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<pow(2,nums.size());i++)
        {
            int temp=i;
            int s=0;
            for(int j=nums.size()-1;j>=0;j--)
            {
                if(temp%2!=0)
                s^=nums[j];
                temp/=2;
            }
            sum+=s;
        }
        return sum;
    }
};