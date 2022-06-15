class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int count=0,a=0,b=plants.size()-1,capA=capacityA,capB=capacityB;
        while(a<=b)
        {
            if(a==b)
            {
                int mx=max(capacityA,capacityB);
                if(mx<plants[a])
                    count++;
            }
            else
            {
                if(capacityA<plants[a])
                {
                    capacityA=capA;
                    count++;
                }
                if(capacityB<plants[b])
                {
                    capacityB=capB;
                    count++;
                }
                capacityA-=plants[a];
                capacityB-=plants[b];
            }
            a++;
            b--;
        }
        return count;
    }
};