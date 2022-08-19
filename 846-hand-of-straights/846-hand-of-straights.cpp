class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> av;
        sort(hand.begin(),hand.end());
        for(auto i:hand) av[i]++;
        for(int i=0;i<hand.size();i++){
            if(av[hand[i]]<=0) continue;
            else if(av[hand[i]]>0){
                av[hand[i]]--;
                for(int j=1;j<groupSize;j++){
                    if(av[hand[i]+j]>0)
                        av[hand[i]+j]--;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};