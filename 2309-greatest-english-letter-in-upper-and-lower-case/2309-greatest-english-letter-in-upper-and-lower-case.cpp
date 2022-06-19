class Solution {
public:
    string greatestLetter(string s) {
        string ans="";
        int arr[129]={0};
        for(auto i:s)
        {
            cout<<(int)i<<" ";
            if(arr[(int)i]==0)
            arr[(int)i]++;
        }       
        for(int i=90;i>=65;i--)
        {
           if(arr[i]==1&&arr[i+32]==1)
               return ans+=(char)i;
        }
        return ans;
    }
};