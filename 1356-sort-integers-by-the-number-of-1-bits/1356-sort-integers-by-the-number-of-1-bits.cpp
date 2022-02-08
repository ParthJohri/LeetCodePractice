class Solution {
public:
    int countBits(int n)
    {
        int count=0;
        while(n)
        {
            ++count;
            n=n&(n-1);
        }
        return count;
    }
    static bool check(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.second!=p2.second) 
            return p1.second<p2.second; 
        return p1.first<p2.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> m;
        vector<int> v;
        int c=0;
        for(int i=0;i<arr.size();i++)
        {
            c=countBits(arr[i]);
            m.push_back(make_pair(arr[i],c));
        }
        sort(m.begin(),m.end(),check);
        for(auto i:m)
            v.push_back(i.first);
        return v;
    }
};