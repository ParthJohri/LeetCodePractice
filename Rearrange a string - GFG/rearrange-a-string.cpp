// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        int sum=0;
        string s="";
        for(auto i:str)
        {
            if(i>='A'&&i<='Z')
            s+=i;
            else if(i>='0'&&i<='9')
            sum+=stoi(to_string(i-'0'));
        }
        sort(s.begin(),s.end());
        s+=to_string(sum);
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends