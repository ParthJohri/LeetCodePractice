class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int totalsum=0,leftovercards=0,sum=0,mn=INT_MAX;
        for(auto i:card) totalsum+=i;
        leftovercards=card.size()-k;
        for(int i=0;i<leftovercards;i++)
            sum+=card[i];
        mn=sum;
        for(int i=leftovercards;i<card.size();i++)
        {
            sum+=card[i]-card[i-leftovercards];
            mn=min(mn,sum);
        }
        return totalsum-mn;
    }
};