class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
            int j=i-1;
            int curr_or=arr[i];
            int prev_or=0;
            while(j>=0 and curr_or!=prev_or){
                curr_or|=arr[j];
                prev_or|=arr[j];
                s.insert(curr_or);
                j--;
            }
        }
        return s.size();
    }
};