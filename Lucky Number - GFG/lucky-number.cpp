// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isLuckyOrNot(long long N) {
        // code 
        int count=0;
        set<long long int> s;
        if(N<9)
            return 1;
        while(N!=0)
        {
            if(N%10==1)
            return 0;
            s.insert(N%10);
            ++count;
            N=N/10;
        }

        return s.size()==count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isLuckyOrNot(N) << endl;
    }
    return 0;
}  // } Driver Code Ends