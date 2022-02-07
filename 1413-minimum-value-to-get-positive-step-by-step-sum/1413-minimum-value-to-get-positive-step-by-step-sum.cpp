class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=1,sum=0;
        vector<int> prefix;
        
        for(auto i:nums)
            {sum+=i;
             prefix.push_back(sum);}
        
        for(ans=1;;ans++)
        {int count=0;
            for(int i=0;i<prefix.size();i++)
            {
                if(ans+prefix[i]>=1)
                    ++count;
            }
         if(count==prefix.size())
             break;
        }
        return ans;
    }
};