// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isLuckyOrNot(long long N) {
        // code 
        long long Num=N;
        vector<string> v;
        int count=0;
        set<long long int> s;
        while(Num!=0)
        {
            v.push_back(to_string(Num%10));
            s.insert(Num%10);
            ++count;
            Num=Num/10;
        }
        long long int p=1;
        long long int value=count*(count+1)/2;
        for(int i=0;i<v.size();i++)
        {p=stoi(v[i]);
            for(int j=i+1;j<v.size();j++)
            {
                p*=stoi(v[j]);
                s.insert(p);
            }
            
        }
        return s.size()==value;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isLuckyOrNot(N) << endl;
    }
    return 0;
}  // } Driver Code Ends