class Solution {
public:
    int secondHighest(string s) {
        set<int> ans;
        for(auto i:s)
        {
            if(isdigit(i))
            {
                ans.insert(i-'0');
            }
        }
        if(ans.size()==0)
            return -1;
        auto i1=ans.end();
        i1--;
        int n1=*i1;
        i1--;
        int n2=*i1;
        return n1==n2?-1:n2;
    }
};