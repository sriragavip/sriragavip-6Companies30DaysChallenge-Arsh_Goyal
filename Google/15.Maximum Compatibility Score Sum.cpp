class Solution {
    int used[9] = {}, ans = 0, m, n;
    void dfs(vector<vector<int>>& S, vector<vector<int>>& M, int i, int score) {
        if (i == m) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (used[j]) continue;
            used[j] = 1;
            int s = 0;
            for (int k = 0; k < n; ++k) s += S[i][k] == M[j][k]; 
            dfs(S, M, i + 1, score + s);
            used[j] = 0;
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& S, vector<vector<int>>& M) {
        m = S.size(), n = S[0].size();
        dfs(S, M, 0, 0);
        return ans;
    }
};