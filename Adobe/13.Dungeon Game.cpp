class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 0;
        
        const int M = dungeon.size(), N = dungeon.front().size();
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        
        for(int i = M - 1; i >= 0; i--) {
            for(int j = N - 1; j >= 0; j--) {
                if(i == M - 1 && j == N - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if(i == M - 1) 
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
                else if(j == N - 1) 
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
                else  
                    dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};