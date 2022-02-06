class Solution {
public:
    // whenever we pass a compare function 
    // in sort then it should be declared as static
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

        // creating a vector of pairs 
        // to store values in key value pairs
        
        vector<pair<int,int> > v;
        
        for(int i=0;i<power.size();i++)
        {
            v.push_back(make_pair(i,power[i]));
        }
        // sorting the vector of pairs 
        // according to the second value 
        // if they are equal then by their first value
        
        sort(v.begin(),v.end(),comp);
        
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};