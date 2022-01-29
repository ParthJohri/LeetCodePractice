class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length(),x=0,as=0,ds=n;
        vector<int> perm(n+1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
            {
                perm[x++]=as++;
            }
            else if(s[i]=='D')
            {
                perm[x++]=ds--;
            }
        }
        perm[n]=as++;
        return perm;
    }
};