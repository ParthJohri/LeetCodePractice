class Solution {
public:
    static bool comp(const pair<int,int> &l,const pair<int,int> &r)
    {
        if(l.second!=r.second)
            return l.second<r.second;
        return l.first<r.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int start,end,pos,num;
        vector<int> power;
        for(auto i:mat)
        {
            vector<int> v=i;
            start=0,end=v.size()-1;
            while(start<end)
            {
                int mid=start+(end-start)/2;
                if(v[mid]-v[mid+1]==1)
                {
                    start=mid;
                    break;
                }
                else if(v[mid]-v[mid+1]==0&&v[mid]==1)
                {
                    start=mid+1;
                }
                else
                    end=mid-1;
            }
            if(v[0]==0)
                start=-1;
            power.push_back(start+1);
        }
        unordered_map<int,int> m;
        for(int i=0;i<power.size();i++)
        {
            m[i]=power[i];
        }
        vector<pair<int,int> > v;
        for(auto i=m.begin();i!=m.end();i++)
        {
            v.push_back(make_pair(i->first,i->second));
        }
        
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};