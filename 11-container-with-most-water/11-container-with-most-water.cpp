class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,mx=INT_MIN,mn=INT_MAX,width=0,area=0;
        while(i<j)
        {
            mn=min(height[i],height[j]);
            width=j-i;
            area=width*mn;
            mx=max(mx,area);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return mx;
    }
};