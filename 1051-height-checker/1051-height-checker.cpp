class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int start=0,end=heights.size()-1,count=0;
        vector<int> expected=heights;
        sort(expected.begin(),expected.end());
        for(int i=0;i<heights.size();i++)
        {
            if(expected[i]!=heights[i])
                ++count;
        }
        return count;
    }
};