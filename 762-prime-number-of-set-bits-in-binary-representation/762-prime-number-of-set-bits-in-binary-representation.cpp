class Solution {
public:
    bool prime(int n)
    {
        if(n==1)
            return false;
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            int x=__builtin_popcountll(i);
            if(prime(x))
                ++count;
        }
        return count;
    }
};