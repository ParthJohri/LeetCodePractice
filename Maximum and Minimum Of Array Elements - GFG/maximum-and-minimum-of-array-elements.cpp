#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    vector<int> A;
	    cin>>n;
	    for(int i=0;i<n;i++)
	        {
	            cin>>m;
	        A.push_back(m);
	        }
	    int min=*min_element(A.begin(),A.end());
	    int max=*max_element(A.begin(),A.end());
	    cout<<max<<" "<<min<<endl;
}
}