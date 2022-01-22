class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto i: operations)
        {
            if(i=="++X"||i=="X++")
                x++;
            else if(i=="--X"||i=="X--")\
                x--;
        }
        return x;
    }
};