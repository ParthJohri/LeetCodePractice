class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int start=0;
        int end=n-1;
        int mid=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(target>=letters[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return letters[start%n];
        //if you will not do modulo then start=n which will give runtime error read the line NOTE that the           letters wrap around,
    }
};