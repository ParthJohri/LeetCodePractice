class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=0.0;
        double p=(double)minutes/60*6*5;
        double h=hour<6?0:12;
        double x=(hour-h)*6*5;
        ans=minutes*6-p-x;
        ans=ans>180?ans-360.0:ans;
        return ans<0?-ans:ans;
    }
};