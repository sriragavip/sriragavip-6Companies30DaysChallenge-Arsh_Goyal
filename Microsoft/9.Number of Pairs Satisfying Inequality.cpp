class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for (int i = 0; i < nums1.size(); i++)
            nums1[i] -= nums2[i];
    
        long long ans = 0;
        mergeSort(nums1, 0, nums1.size() - 1, ans, diff);
        return ans;
    }
    
    void mergeSort(vector<int> &nums, int i, int j, long long &ans, int diff) {
        if (i >= j) return;
        
        int mid = (i + j) / 2;      
        mergeSort(nums, i, mid, ans, diff);
        mergeSort(nums, mid + 1, j, ans, diff);
        
        int idx = i;
        for (int k = mid + 1; k <= j; k++) {
            while (idx <= mid && nums[idx] <= nums[k] + diff) {
                idx++;
            }
            ans += (idx - i);
        }
        
        inplace_merge(nums.begin() + i, nums.begin() + mid + 1, nums.begin() + j + 1);
    }  
};