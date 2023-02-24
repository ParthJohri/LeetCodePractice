//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0],startmin=arr[0]+k,startmax=arr[n-1]-k;
        if(k>=arr[n-1]) return ans;
        for(int i=0;i<n-1;i++){
            // 1 5 8 10, k = 11
            if(k>arr[i+1]) continue;
            int currmin=min(startmin,arr[i+1]-k),currmax=max(startmax,arr[i]+k);
            ans=min(ans,currmax-currmin);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends