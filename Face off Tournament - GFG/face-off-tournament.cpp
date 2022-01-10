// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string winner(int x, int m, int n,long long int arr[])
    {
        // code here
        int cx=0,cy=0,y=0,i=0;
        for(i=0;i<x;i++)
            {y=arr[i];
                if(y%m==0)
                ++cx;
                else if(y%n==0)
                ++cy;
            }
            if(cx>cy)
            return "Ram";
            if(cx<cy)
            return "Rohan";
            if(cx==cy)
            return "Both";
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, m, n;
        cin>>x>>m>>n;
        long long arr[x];
        for(int i = 0;i < x;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.winner(x, m, n, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends