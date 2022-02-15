class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> arr;
        

        for(int i=0;i<queries.size();i++){
            int cx=queries[i][0];
            int cy=queries[i][1];
            double r=queries[i][2];
            int count=0;
        for(auto i:points)
        {
            int x=i[0];
            int y=i[1];
            double d=sqrt(pow((x-cx),2)+pow((y-cy),2));
            if(d<=r)
                ++count;
        }
            arr.push_back(count);
        }
        return arr;
    }
};