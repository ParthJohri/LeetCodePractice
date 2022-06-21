class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> p;
        for(int i=0;i<h.size()-1;i++)
        {
            if(h[i]>=h[i+1]) continue;
            bricks-=h[i+1]-h[i];
            p.push(h[i+1]-h[i]);
            if(bricks<0)
            {
                bricks+=p.top();
                p.pop();
                    if(ladders>0)
                ladders--;
                else
                    return i;
            }
        }
        return h.size()-1;
    }
};