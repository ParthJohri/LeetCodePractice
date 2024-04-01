class Solution {
public:
    int lengthOfLastWord(string s) {
        string w="";
        int len=0;
        s+=" ";
        for(auto i:s){
            if(i==' '){
                if(w!="")
                    len=w.length();
                w="";
            }
            else{
                w+=i;
            }
        }
        return len;
    }
};