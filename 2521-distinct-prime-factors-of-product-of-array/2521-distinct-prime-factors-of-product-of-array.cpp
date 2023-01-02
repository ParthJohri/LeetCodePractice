class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for(auto pr:nums){
            for(int i=2;i*i<=pr;i++){
            while(pr%i==0){
                s.insert(i);
                pr/=i;
            }
        }
        if(pr!=1) s.insert(pr);
        }
        return s.size();
    }
};