class Solution {
public:
    bool isNumber(const string &s)
    {
        for(auto i:s)
        {if(isdigit(i)==0)
         return false;}
        return true;
    }
    bool areNumbersAscending(string s) {
        stringstream str(s);
        vector<int> st;
        string temp;
        while(str>>temp)
        {
            if(isNumber(temp))
            {int t=stoi(temp);
             st.push_back(t);}
        }
        int count=0;
        for(int i=0;i<st.size()-1;i++)
        {
            if(st[i]<st[i+1])
                ++count;
        }
        return count==st.size()-1;
    }
};