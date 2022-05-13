class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int x=0;
        vector<string> s;
        for(int j=1;j<=n;j++)
        {
            while(x<target.size())
            {
                if(target[x]==j)
                    {s.push_back("Push");
                     x++;
                     break;}
                else if(target[x]!=j&&target[x]>j)
                    {s.push_back("Push");
                     s.push_back("Pop");
                     break;}
                else if(target[x]<j)
                    return s;
            }
        }
        return s;
    }
};