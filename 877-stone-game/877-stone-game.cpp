class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int ev=0,od=0;
        for(int i=0;i<piles.size();i++){
            if(i%2==0)
                ev+=piles[i];
            else
                od+=piles[i];
        }
        return ev!=od;
    }
};