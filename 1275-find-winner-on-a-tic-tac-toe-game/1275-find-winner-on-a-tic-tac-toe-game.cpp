class Solution {
public:
    string recur(vector<vector<string>>&moves){
        string ld="",rd="";
        ld=moves[0][0]+moves[1][1]+moves[2][2];
        rd=moves[0][2]+moves[1][1]+moves[2][0];
        if(ld=="XXX" or rd=="XXX"){
            return "A";
        }
        else if(ld=="OOO" or rd=="OOO"){
            return "B";
        }
        for(int i=0;i<3;i++){
            string s=moves[i][0];
            for(int j=1;j<3;j++){
                if(moves[i][j]==moves[i][j-1]){
                    s+=moves[i][j];
                }
            }
            if(s=="XXX") return "A";
            else if(s=="OOO") return "B";
        }
        for(int i=0;i<3;i++){
            string s=moves[0][i];
            for(int j=1;j<3;j++){
                if(moves[j][i]==moves[j-1][i]){
                    s+=moves[j][i];
                }
            }
            if(s=="XXX") return "A";
            else if(s=="OOO") return "B";
        }
        return "Draw";
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> mat(3,vector<string>(3,"H"));
        int count=0;
        for(auto i:moves){
            if(count%2==0)
                mat[i[0]][i[1]]="X";
            else
                mat[i[0]][i[1]]="O";
            string ans = recur(mat);
            if(ans=="A") return "A";
            else if(ans=="B") return "B";
            count++;
        }
        for(auto i:mat){
            for(auto j:i){
                if(j=="H") return "Pending";
            }
        }
        return "Draw";
    }
};