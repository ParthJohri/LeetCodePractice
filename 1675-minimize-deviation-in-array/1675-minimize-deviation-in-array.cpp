class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans=0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                    nums[i]*=2;
            }
            s.insert(nums[i]);
        }
        
        ans=*s.rbegin()-*s.begin();
    
        while((*s.rbegin())%2==0){
            int temp = *s.rbegin();
            s.erase(temp);
            s.insert(temp/2);
            ans=min(ans,(*s.rbegin())-(*s.begin()));
        }
        
        return ans;
    }
};