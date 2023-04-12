class Solution {
public:
    int nextGreaterElement(int n) {
        // https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
        string str=to_string(n);
        int position=-1,smallestright;
        for(int i=str.length()-2;i>=0;i--){
            if(str[i]<str[i+1]) {
                position=i;
                break;
            }
        }
        if(position==-1) return -1;
        smallestright=position;
        for(int i=position;i<str.length();i++){
            if(str[position]<str[i]){
                smallestright=i;
            }
        }
        swap(str[position],str[smallestright]);
        sort(str.begin()+position+1,str.end());
        long ans=stol(str);
        return ans>INT_MAX?-1:ans;
    }
};