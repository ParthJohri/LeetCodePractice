class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mn=INT_MAX;
        vector<vector<int>> v;
        for(int i=0;i<arr.size()-1;i++)
        {
            mn=min(mn,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            vector<int> vele;
            if(abs(arr[i]-arr[i+1])==mn)
            {
                vele.push_back(arr[i]);
                vele.push_back(arr[i+1]);
            }
            if(!vele.empty())
            v.push_back(vele);
        }
        return v;
    }
};