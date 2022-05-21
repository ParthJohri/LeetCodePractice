class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Must Read Discuss Section
        // Cantor's Diagonization
        map<int,int> m;
        int val=nums[0].length();
        int mx=(int)pow(2,val);

        for(auto i:nums)
        {
            int v=i.length(),ans=0,x=0;
            while(--v>=0)
            {
                ans+=(i[v]-'0')*(int)pow(2,x++);
            }
            m[ans]++;
        }

        for(int i=0;i<mx;i++)
        {
            if(m[i]==0)
            {
                if(i==0)
                    {
                    string a="";
                        while(val--)
                        {
                            a+="0";
                        }
                        return a;
                    }
                else
                {
                    string a="";
                    while(i!=0)
                    {
                        a=to_string(i%2)+a;
                        i=i/2;
                        val--;
                    }
                    while(val--)
                    {
                        a="0"+a;
                    }
                    return a;
                }
            }
        }
        return "";
    }
};