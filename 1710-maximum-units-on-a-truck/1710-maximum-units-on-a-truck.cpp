class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.size()<2)
        {
            return min(truckSize,boxTypes[0][0])*boxTypes[0][1];
        }
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0,mn=0;
        for(auto i:boxTypes)
        {
            if(truckSize<=0)
                return ans;
            mn=min(i[0],truckSize);
            ans+=i[1]*mn;
            truckSize-=mn;
        }
        return ans;
    }
};