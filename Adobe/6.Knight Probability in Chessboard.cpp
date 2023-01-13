#define ll long long int
#define ld long double
class Solution {
public:
    vector<vector<int>> dis={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    double recurse(int n,int row,int col,int k,vector<vector<vector<ld>>> &dp)
    {
        if(row<0||row>=n||col<0||col>=n)
        return 0.0;
        if(k==0)
        return 1.0;
        if(dp[row][col][k]!=-1)
        return dp[row][col][k];
        ld moves=0.0;
        for(auto z:dis)
        {
            int x=row+z[0],y=col+z[1];
            moves+=recurse(n,x,y,k-1,dp)/8.0;
        }
        return dp[row][col][k]=moves;
    }
    double knightProbability(int n,int k, int row, int col) {
        vector<vector<vector<ld>>> dp(n+1,vector<vector<ld>>(n+1,vector<ld>(k+1,-1)));
        ld prob=recurse(n,row,col,k,dp);
        return prob;
    }
};