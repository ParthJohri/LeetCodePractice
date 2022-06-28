class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>f;
        for(auto i:s) f[i]++;
        unordered_map<int,int>m;
        for(auto i:f) m[i.second]++;
        int count=0;
        cout<<"f map\n";
        for(auto i:f)
        {
            cout<<i.first<<"\t"<<i.second<<"\n";
            if(m[i.second]>1)
            {
                cout<<"m map\n";
                cout<<i.second<<"\t"<<m[i.second]<<"\n";
                int t=i.second;
                while(m[i.second]>=1&&i.second!=0)
                {
                    ++count;
                    i.second=i.second-1;
                    cout<<i.second<<"\t"<<m[i.second]<<"\t"<<count<<"\n";
                }
                m[t]--;
                m[i.second]++;
            }
        }
        return count;
    }
};