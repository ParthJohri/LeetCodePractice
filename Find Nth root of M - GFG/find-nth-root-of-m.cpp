// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l=1,r=m,error=0.0001;
	    while(l<=r)
	    {
	        int mid=l+(r-l)/2;
	        double val=1.0;
	        for(int i=1;i<=n;i++)
	        val*=mid;
	        if(val==m) return mid;
	        else if(val>m) r=mid-1;
	        else l=mid+1;
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends