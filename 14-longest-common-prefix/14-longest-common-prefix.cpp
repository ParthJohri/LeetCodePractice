class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="",mn=*min_element(strs.begin(),strs.end()),mx=*max_element(strs.begin(),strs.end());
        int i=0;
        while(i<mn.length())
        {
            if(mn[i]==mx[i])
                ans+=mn[i];
            else
                break;
            i++;
        }
        return ans;
    }
};