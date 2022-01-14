class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=checkBit(i);
        }
    return ans;}
    int checkBit(int n)
    {
        int k=0;
        int count=0;
        while(k<=31)
        {
            if(((1<<k)&n)>0)
            ++count;
            k++;
        }
        return count;
    }
};