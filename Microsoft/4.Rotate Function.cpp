class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int current = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            current += i * nums[i];
        }
        int max = current;
        int index = nums.size() -1;
        
        while (index > 0) {
            current = current - nums.size() * nums[index--] + sum;
            if (max < current)
                max = current;
        }
        return max;
    }
};