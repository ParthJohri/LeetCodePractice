class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> n(2*nums.size());
        int i,j,x=0,K=0,ans=INT_MAX,swap1=INT_MAX,ones=0,zero=0;

        for(auto i:nums)
        {
            n[x++]=i;
            if(i==1)
             ++K;
        }
        
        if(K==0)
            return 0;

        for(auto i:nums)
        {
            n[x++]=i;
        }
        
        cout<<n.size()<<"\n";
        for(auto i:n)
            cout<<i<<" ";
        cout<<"\n****************\n";

        for(int i=0;i<K;i++)
        { 
            if(nums[i]==1)
                ones++;
            else
                zero++;
        }
        cout<<zero<<"\n";
    
        for(int i=K;i<n.size();i++)
        {
            if(n[i-K]==0&&n[i]==1)
            {
                ones++;
                zero--;
            }
            else if(n[i-K]==1&&n[i]==0)
            {
                ones--;
                zero++;
            }
            ans=zero;
            swap1=min(ans,swap1);
        }
        return swap1;
    }
};