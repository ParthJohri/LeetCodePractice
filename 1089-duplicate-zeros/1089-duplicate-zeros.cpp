class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
     int i=0,j=arr.size()-1;
        vector<int> v;
        while(i<=j)
        {
            if(arr[i]==0)
                {v.push_back(0);
                j--;}
            v.push_back(arr[i]);
            i++;
        }
        for( i=0;i<arr.size();i++)
            arr[i]=v[i];
    }
};