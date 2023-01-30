class Solution {
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        
        //prefix sum
        long prefixsum[]=new long[n+1];
        for(int i=1;i<=n;i++){
            prefixsum[i] = prefixsum[i-1]+nums[i-1];
        }

        Stack<Integer>st1=new Stack<>();
        Stack<Integer>st2=new Stack<>();

        int left[]=new int[n];
        int right[]=new int[n];
        
        //left MIN
        for(int i=0;i<n;i++){
            while(!st1.isEmpty() && nums[i]<=nums[st1.peek()])st1.pop();
            if(st1.isEmpty())left[i]=-1;
            else left[i]=st1.peek();
            st1.push(i);
        }
        //right MIN
        for(int i=n-1;i>=0;i--){
            while(!st2.isEmpty() && nums[i]<=nums[st2.peek()])st2.pop();
            if(st2.isEmpty())right[i]=n;
            else right[i]=st2.peek();
            st2.push(i);
        }

        long max=0;
        for(int i=0;i<n;i++){
            int l = left[i];
            int r = right[i];
            long sum = prefixsum[r]-prefixsum[l+1];
            long prod = sum*nums[i];
            max = Math.max(max,prod);
        }
        return (int)(max%1000000007);
    }
}