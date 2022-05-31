class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long int sum=0;
        map<int,int> m;
        for(int i=0;i<k;i++)
            m[i]=0;
        int count=0;
        if(s.length()<k)
            return false;
        for(int i=0;i<=s.length()-k;i++)
        {
            string str=s.substr(i,k);
            int x=0;
            sum=0;
            for(int i=str.length()-1;i>=0;i--)
            {
                sum+=str[i]*pow(2,x++);
            }
            m[sum]++;
        }
        for(auto i:m)
        {
            if(i.second>=1)
                ++count;
        }
        return count==pow(2,k);
    }
};