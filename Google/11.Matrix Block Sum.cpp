class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans( n,vector<int> (m, 0));
        for(int i=1; i<n; i++) mat[i][0] += mat[i-1][0];
        for(int i=1; i<m; i++) mat[0][i] += mat[0][i-1];
        for(int r=1; r<n; r++) for(int c = 1; c<m; c++)
                mat[r][c] += mat[r-1][c] + mat[r][c-1] - mat[r-1][c-1];
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                int r_max = min(n-1,i+k), c_max = min(m-1,j+k);
                if (i>k && j>k) ans[i][j] = mat[r_max][c_max] + mat[i-k-1][j-k-1] 
                        - mat[r_max][j-k-1] - mat[i-k-1][c_max];
                else if (i>k) ans[i][j] = mat[r_max][c_max] - mat[i-k-1][c_max];
                else if (j>k) ans[i][j] = mat[r_max][c_max] - mat[r_max][j-k-1];
                else ans[i][j] = mat[r_max][c_max];
            }
        }
        return ans;
    }
};