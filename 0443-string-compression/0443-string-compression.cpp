class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int count=1,x=0;
        for(int i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                if(count==1)
                    s+=chars[i];
                else
                s+=chars[i]+to_string(count);
                count=1;
            }
        }
         if(count==1)
            s+=chars[chars.size()-1];
        else
            s+=chars[chars.size()-1]+to_string(count);
        for(int i=0;i<s.length();i++){
            chars[x++]=s[i];
        }
        return s.length();
    }
};