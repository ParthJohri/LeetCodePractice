class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        // Pta kya ho rha tha na dekho pehle a dhundo woh toh tum sahi jaa rhe the
        // ki sabse chota hoga mil gya a mein
        // ab a se bada but second minimum woh b hai 
        // woh bhi mil gya toh kyun bethe ho khali
        // bajao tali kyunki mil gye tumko triplet
        // jo bhi yeh padh rha hai bhai mere ko bhi smjh nhi aarha ab toh kyun likh rha hoon mein :)
        for(auto i:nums){
            if(a>=i){
                a=i;
            }
            else if(b>=i){
                b=i;
            }
            else return true;
        }
        return false;
    }
};