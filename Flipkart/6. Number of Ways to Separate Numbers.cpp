#define M 1000000007
#define N 3501

int zi[N][N], dp[N][N];
class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        for(int i = n-1; i >= 0; i--)
            for(int j = n-1; j >= i+1; j--)
                zi[i][j] = (num[i] == num[j]) ? zi[i+1][j+1]+1 : 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(num[j+1] == '0') {
                    dp[i][i-j] = dp[i][i-j-1];
                    continue;
                }
                int len = i-j, k = 2*j-i + 1,
                useLength = len - (k >= 0 && zi[k][j+1] < len && num[k+zi[k][j+1]] > num[j+zi[k][j+1]+1]);
                dp[i][len] = (dp[i][len-1]+dp[j][min(useLength, j+1)])%M;
            }
            dp[i][i+1] = (dp[i][i] + (num[0] != '0'))%M;
        }
        return dp[n-1][n];
    }
};