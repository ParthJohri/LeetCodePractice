class NumArray
{
    public:

        vector<int> bit, num;
        int n;

    NumArray(vector<int> &nums)
    {

        num = nums;
        bit.resize(nums.size() + 1, 0);
        n = nums.size();

        for (int i = 1; i <= n; i++)
        {
            init(i, nums[i - 1]);
        }
    }

    void init(int i, int val)
    {
        for (; i <= n; i += (i &(-i)))
        {
            bit[i] += val;
        }
    }
    
    int sum(int index)
    {
        int ans = 0;
        while (index > 0)
        {
            ans += bit[index];
            index -= (index &(-index));
        }
        return ans;
    }

    void update(int index, int val)
    {
        int i = index + 1;
        for (; i <= n; i += (i &(-i)))
        {
            bit[i] += val - num[index];
        }
        num[index] = val;
    }

    int sumRange(int left, int right)
    {
        return sum(right + 1) - sum(left);
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *obj->update(index,val);
 *int param_2 = obj->sumRange(left,right);
 */