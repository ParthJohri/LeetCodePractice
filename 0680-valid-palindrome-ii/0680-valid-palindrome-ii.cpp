class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length(),i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                break;
        }
        if(i>=j) return true;
        int tempi=i,tempj=j;
        cout<<tempi<<" "<<tempj<<endl;
        i=tempi,j=tempj-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                break;
        }
        if(i>=j) return true;
        i=tempi+1,j=tempj;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                break;
        }
        if(i>=j) return true;
        return false;
    }
};