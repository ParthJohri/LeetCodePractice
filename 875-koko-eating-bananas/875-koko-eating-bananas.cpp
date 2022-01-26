class Solution {
public:
    int found(vector<int>piles,int k)
    {
        int count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=piles[i]%k==0?piles[i]/k:piles[i]/k+1;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int start=1,end=*max_element(piles.begin(),piles.end());
        if(piles.size()==h)
            return end;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(found(piles,mid)<=h)
                end=mid-1;
            else
                start=mid+1;
        }
    return start;
    }
};