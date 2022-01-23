class Solution {
public:
    int hammingDistance(int x, int y) {
        int s=x^y;
        int count=0;
        while(s!=0)
        {
            s=s&(s-1);
            ++count;
        }
        return count;
    }
};