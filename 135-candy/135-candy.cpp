class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        // Refer this video solution 
        // https://www.youtube.com/watch?v=sSwB4ggwzVY&ab_channel=CodingDecoded
        // Traversing from Left to Right
        for(int i=0;i<ratings.size()-1;i++)
        {
            if(ratings[i+1]>ratings[i])
            candies[i+1]=candies[i]+1;
        }
        // Traversing from Right to Left
        for(int i=ratings.size()-1;i>=1;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(candies[i-1]<=candies[i])
                    candies[i-1]=candies[i]+1;
            }
        }
        int totalmincandies=0;
        for(auto i:candies)
            totalmincandies+=i;
        return totalmincandies;
    }
};