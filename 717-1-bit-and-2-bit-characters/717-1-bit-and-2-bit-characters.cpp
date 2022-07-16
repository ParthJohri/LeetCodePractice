class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0,n=bits.size();
        while(i<n){
            if(i==n-1) return true;
            if(i==n-2) return bits[i]==0;
            if(bits[i]==0) i++;
            else if(bits[i]==1) i+=2;
        }
        return false;
    }
};