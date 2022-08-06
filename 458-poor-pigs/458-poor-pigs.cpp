class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int numberOfRounds=(minutesToTest/minutesToDie)+1,pigs=0;
        while(pow(numberOfRounds,pigs)<buckets){
            pigs++;
        }
        return pigs;
    }
};  