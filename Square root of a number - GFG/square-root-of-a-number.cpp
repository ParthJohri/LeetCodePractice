// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        int start=1;
        int end=x;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid==x/mid)
            return mid;
            else if(mid>x/mid)
            end=mid-1;
            else
            {
                start=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends