class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> num=score;
        sort(score.begin(),score.end(),greater<int>());
        map<int,string> m;
        int p=1;
        for(auto i:score){
            if(p==1){
                m[i]="Gold Medal";
            }
            else if(p==2){
                m[i]="Silver Medal";
            }
            else if(p==3){
                m[i]="Bronze Medal";
            }
            else
            m[i]=to_string(p);
            p++;
        }
        for(auto i:num){
            ans.push_back(m[i]);
        }
        return ans;
    }
};