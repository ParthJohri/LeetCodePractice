// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	map<int,int> fac={{0,1},{1,1},{2,2},{3,6},{4,24},{5,120},{6,720},{7,5040},{8,40320},{9,362880}};
	string val(int N, int c)
	{
	    if(N==0||c<0)
	    return "";
	    if(fac[c]>N) return val(N,c-1);
	    else
	    return val(N-fac[c],c)+to_string(c);
	}
	vector<int> FactDigit(int N)
	{
	    // Code here
	   vector<int> v;
	   string s=val(N,9);
	   for(auto i:s)
	   v.push_back(i-'0');
	   return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}  // } Driver Code Ends