class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr.push_back(INT_MAX);
        map<int,int> m;
        for(int i=0;i<arr.size()-1;i++){
            int cnt=1;
            while(arr[i]==arr[i+1]){
                cnt++;
                i++;
            }
            if(m.count(cnt)) return false;
            m[cnt]++;
        }
        return true;
    }

};