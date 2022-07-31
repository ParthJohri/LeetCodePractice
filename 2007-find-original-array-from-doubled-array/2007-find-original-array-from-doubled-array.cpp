class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        if(nums.size()%2!=0)
            return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m,n;
        vector<int> v;
        int countz=0;
        set<int> s;
        for(auto i:nums){
           n[i]++;
           if(i!=0)
           s.insert(i);
           if(i==0)
               ++countz;
        }
        for(auto i:s){
            if(n.count(i) && n.count(i*2)){
                int mn=min(n[i],n[i*2]);
                n[i]-=mn;
                n[i*2]-=mn;
                while(mn--)
                v.push_back(i);
            }
        }
        if(countz%2==0){
            countz=countz/2;
            while(countz--){
                v.push_back(0);
            }
        }
        if(v.size()*2==nums.size())
            return v;
        return {};
    }
};