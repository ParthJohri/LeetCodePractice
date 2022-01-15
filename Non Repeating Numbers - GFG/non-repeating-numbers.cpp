// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorr=0;
        vector<int>a(2);
        for(int i=0;i<nums.size();i++)
        {
            xorr^=nums[i];
        }
        int sn=(xorr&(~(xorr-1)));
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&sn)!=0)
            {
               a[0]^=nums[i];
            }
            else
            {
                a[1]^=nums[i];
            }
        }
         sort(a.begin(),a.end());
         return a;
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
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends