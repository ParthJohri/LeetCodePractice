class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int count=0,cap=capacity;
        for(int i=0;i<plants.size()-1;i++)
        {
            if(capacity>=plants[i])
            {
                capacity-=plants[i];
                count++;
            }
            if(capacity<plants[i+1])
            {
                count+=2*(i+1);
                capacity=cap;
            }
        }
        return count+1;
    }
};