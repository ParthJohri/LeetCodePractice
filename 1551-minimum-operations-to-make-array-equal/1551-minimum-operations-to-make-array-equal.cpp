class Solution {
public:
    int minOperations(int n) {
        int v=0;
        if(n%2==0)
           v=(2*(n/2 - 1)+1 + 2*(n/2+1 -1)+1)/2;
        else
            v=(2*(n/2)+1);
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            a.push_back(2*i+1);
        }
        int ans=0;
        for(int i=0;i<a.size()/2;i++)
        {
            cout<<a[i];
            ans+=abs(a[i]-v);
        }
        return ans;
    }
};
