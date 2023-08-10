class Solution
{
    public:
        bool search(vector<int> &nums, int target)
        {
            int n = nums.size() - 1;
            int start = 0, end = n;
            while (start <= end)
            {
                while (start < n and start <= end and nums[start] == nums[start + 1])
                {
                    start++;
                }
                while (end > 0 and start <= end and nums[end] == nums[end - 1])
                {
                    end--;
                }
                int mid = start + (end - start) / 2;
                if (nums[mid] == target) return true;

                if (nums[start] <= nums[mid])
                {
                    if (nums[start]<=target and target<=nums[mid])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid]<=target and target<=nums[end])
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
            return false;
        }
};