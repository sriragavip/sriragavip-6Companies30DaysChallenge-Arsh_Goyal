class Solution {
    private int mod = 1000000007;
    public int numberOfWays(int s, int e, int k) {
        int dp[][]=new int[3002][1001];
        for(int []item:dp)Arrays.fill(item,-1);

        return topdown(s,e,s,k,dp);
    }
    private int topdown(int s,int e,int curr,int k,int dp[][]){
        if(k==0){
            if(curr==e)return 1;
            else return 0;
        }
        if(dp[curr+1001][k]!=-1)return dp[curr+1001][k];
        int rightmove = topdown(s,e,curr+1,k-1,dp)%mod;
        int leftmove = topdown(s,e,curr-1,k-1,dp)%mod;

        return dp[curr+1001][k] = (rightmove+leftmove)%mod;
    }
}