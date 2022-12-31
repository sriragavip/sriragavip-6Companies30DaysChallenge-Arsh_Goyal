class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size ();
        sort (nums.begin (), nums.end ());
        vector<int> dp (n, 1);
        vector<int> cnt (n, -1);
        int index, maxi = 0;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if ((nums[i] % nums[j] == 0) && 1 + dp[j] > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> ans;
        while (cnt[index] != -1) {
            ans.push_back (nums[index]);
            index = cnt[index];
        }
        ans.push_back(nums[index]);
        return ans;
    }
};