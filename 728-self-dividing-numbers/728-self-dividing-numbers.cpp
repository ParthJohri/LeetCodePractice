class Solution {
public:
    bool self(int n)
    {
        int t=n;
        while(n!=0)
        {
            int r=n%10;
            if(t%(r!=0?r:1)!=0||r==0)
                return false;
            n=n/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++)
            {if(self(i))
                v.push_back(i);
            }
        return v;
    }
};