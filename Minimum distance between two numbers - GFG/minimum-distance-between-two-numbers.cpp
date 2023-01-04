//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int v1=-1,v2=-1,mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]==x) v1=i;
            else if(a[i]==y) v2=i;
            if(v1!=-1 and v2!=-1){
                mn=min(mn,abs(v2-v1));
            }
        }
        if(v1==-1 or v2==-1) return -1;
        return mn;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends