class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string str="",word="";
        if(path[path.length()-1]!='/') path+="/";
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(word==".."){
                    if(!s.empty())
                    s.pop();
                }
                else if(word!="" and word!=".") {
                    s.push(word);
                }
                word="";
            }
            else
                word+=path[i];
        }
        while(!s.empty()){
            str="/"+s.top()+str;
            s.pop();
        }
        return str.length()==0?"/":str;
    }
};