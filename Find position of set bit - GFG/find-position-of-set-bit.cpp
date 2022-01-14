// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int k=0,pos=0,count=0;
            if(N==0)
            {return -1;}
        while(k<=31)
        {
            if((N&(1<<k))>0)
            {
                if(count==0)
                {pos=k;}
                count++;
            }
            if(count>1)
            {return -1;}
        k++;
        }
         return (pos+1);  
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends