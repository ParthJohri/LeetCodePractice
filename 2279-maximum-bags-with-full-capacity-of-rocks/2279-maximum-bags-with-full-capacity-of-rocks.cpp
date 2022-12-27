class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        long long int count=0;
        vector<long long int> v;
        for(int i=0;i<capacity.size();i++)
        {
            count+=capacity[i]-rocks[i];
            v.push_back(capacity[i]-rocks[i]);
        }
        if(additionalRocks>=count)
            return capacity.size();
        sort(v.begin(),v.end());
        long long int c=0;
        for(auto i:v)
        {
            if(i==0)
                ++c;
            else
            {
                if(additionalRocks>=i)
                {
                    additionalRocks-=i;
                                ++c;
                }
                if(additionalRocks==0 || additionalRocks<i)
                    return c;
            }
        }
        return c;
    }
};