class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        for(auto i: items)
        {
            if(ruleKey=="color")
            {
                if(ruleValue==i[1])
                    ++count;
            }
            else if(ruleKey=="type")
            {
                if(ruleValue==i[0])
                    ++count;
            }
            else if(ruleKey=="name")
            {
                if(ruleValue==i[2])
                    ++count;
            }
        }
        return count;
    }
};