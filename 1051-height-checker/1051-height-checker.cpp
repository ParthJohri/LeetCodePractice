class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int start=0,end=heights.size()-1,count=0;
        vector<int> expected;
        // sort(expected.begin(),expected.end()); nlog(n) 
        int arr[101]={0};
        for(auto i: heights)
        {
            arr[i]++;
        }
        for(int i=1;i<101;i++)
        {
            int j=arr[i];
            while(j--)
            {
                expected.push_back(i);
            }
        }
        for(int i=0;i<heights.size();i++)
        {
            if(expected[i]!=heights[i])
                ++count;
        }
        return count;
    }
};