class Solution {
public:
    int words(string s)
    {
        int count=0;
        for( auto i:s)
            {if(i==' ')
                ++count;}
        return count+1;
    }
    int mostWordsFound(vector<string>& sentences) {
        int count=0,maxi=0;
        for(auto i:sentences)
        {
            count=words(i);
            maxi=max(count,maxi);
        }
        return maxi;
    }
};