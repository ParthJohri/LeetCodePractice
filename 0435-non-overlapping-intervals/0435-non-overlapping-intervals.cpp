class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[](vector<int>&a, vector<int>&b){
             return a[1]<b[1];
        });
        int n=i.size();
        i.push_back({INT_MIN,INT_MIN});
        for(auto j:i){
            cout<<"{"<<j[0]<<","<<j[1]<<"},";
        }
        vector<vector<int>> ni;
        ni.push_back({i[0][0],i[0][1]});
        for(int j=1;j<i.size()-1;j++){
            if(i[j][0]<ni[ni.size()-1][1])
                continue;
            else
                ni.push_back({i[j][0],i[j][1]});
        }
        cout<<endl;
        for(auto j:ni){
            cout<<"{"<<j[0]<<","<<j[1]<<"},";
        }
        cout<<endl;
        return n-ni.size();
    }
};