class Solution {
public:
    int findIntegers(int num) {
        int dp[105][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1,dp[0][1]=1;
        for(int i=1;i<=32;++i){
            dp[i][1]=dp[i-1][0];
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
        }
        int bit[105],tmp=num,l=0;
        while(tmp){
            bit[l++]=tmp&1;
            tmp=tmp>>1;
        }
        int ans=0,pre=-1,ok=1;
        for(int i=l-1;i>=0;--i){
            if(bit[i]==1){
                ans+=(i==0?1:dp[i-1][1]+dp[i-1][0]);
                if(pre==1) {ok=0;break;}
            }
            if(pre==1) pre=0; else pre=bit[i];
        }
        return ans+ok;
    }
};