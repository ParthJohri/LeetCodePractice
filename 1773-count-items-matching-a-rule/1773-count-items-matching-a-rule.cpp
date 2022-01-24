class Solution {
public:

    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index=ruleKey=="type"?0:ruleKey=="color"?1:2;//finding the asked index
        // using count_if function of algorithm header file
        // syntax count_if(start,end,condition);
        // https://www.tutorialspoint.com/count-if-in-cplusplus-stl
        // [&] means call by reference
        // [&] (auto i){ return i[index]==ruleValue is a lambda function, it a one liner function}
        return count_if(items.begin(),items.end(),[&](auto &i){return i[index]==ruleValue;});
    }
};