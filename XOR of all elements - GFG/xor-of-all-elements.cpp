// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> getXor(vector<int> A, int N)
    {
        vector<int> x;
        int sum=0;
        for(int i=0;i<A.size();i++)
        {   
            sum^=A[i];
        }
        for(int i=0;i<A.size();i++)
        {
            x.push_back(sum^A[i]);
        }
    return x;}
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N ;
        vector<int> A(N);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        Solution ob;
        vector<int> B = ob.getXor(A, N);
        for(int i = 0 ; i < N ; i++)
        {
            cout << B[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends