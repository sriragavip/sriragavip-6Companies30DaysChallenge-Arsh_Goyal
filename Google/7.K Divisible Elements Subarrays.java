class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        int n = nums.length;
        Set<Long> ways = new HashSet<>(); 
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            long hc = 1; 
            for(int j = i; j < n; j++) {
                hc = 199L * hc + nums[j]; 
                if(nums[j] % p == 0)
                    cnt++;
                if(cnt <= k) {
                    ways.add(hc);
                }
            }
        }
        return ways.size();
    }
}