class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=0,right=1,d=0,mxd=0;
        while(right<colors.size())
        {
            if(colors[left]!=colors[right])
            {
               d=right-left;
               mxd=max(mxd,d);
            }
            right++;
        }
        right=colors.size()-1;
        while(left<colors.size())
        {
            if(colors[left]!=colors[right])
            {
               d=right-left;
               mxd=max(mxd,d);
            }
            left++;
        }
        return mxd;
    }
};