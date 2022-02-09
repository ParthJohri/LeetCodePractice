class Solution {
public:
    int secondHighest(string s) {
        // using Ordered Set that takes Average O(logn) TC
        set<int> ans;
        for(auto i:s)
        {
            if(isdigit(i))
            {
                ans.insert(i-'0');
            }
        }
        // To check if there is no element
        // Otherwise in the next step, it will cause runtime error
        if(ans.size()==0)
            return -1;
        // Set is n associative container for accessing the elements
        // we are using an iterator i1 and pointing it to the end of 
        // the set which is imaginary 
        auto i1=ans.end();
        // For last element 
        i1--;
        // For the number at the last element
        int n1=*i1;
        // For the second last element
        i1--;
        // For the number at the second last element
        int n2=*i1;
        // Checking if the numbers are equals means -1 else n2
        return n1==n2?-1:n2;
    }
};