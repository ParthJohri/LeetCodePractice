// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        long long int low=0,high=a.size()-1,mid=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(low==high)
            return a[low];
            else if(a[mid]<a[mid+1])
            low=mid+1;
            else 
            high=mid;
        }
        return -1;
    }
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}

  // } Driver Code Ends