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
            // If height[i]<height[j] we move ahead to check for maximum area.
            // Why do we not check for j-1,j-2,j-3 if height[i]<height[j]
            // Because width will decrease and mn will remain the same, making the new 
            // area Anew < area Aold. 
            if(height[i]<=height[j])
                i++; 
            else
                j--;
        }
        return mx;
    }
};