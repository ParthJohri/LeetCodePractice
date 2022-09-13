class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int answer=0,mx=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<=j and j>=0 and i<=tokens.size()-1){
            if(power>=tokens[i] and power>=0){
                power-=tokens[i];
                answer++;
                i++;
            }
            else if(power<=tokens[i] and answer>0){
                answer--;
                power+=tokens[j--];
            }
            else
                break;
            // cout<<power<<" "<<answer<<endl;
            mx=max(mx,answer);
        }
        return mx;
    }
};