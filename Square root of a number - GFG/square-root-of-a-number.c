// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

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

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends