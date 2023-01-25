class Solution {
public:
    int n, ans = 0;
    int maximumGood(vector<vector<int>>& S) {
        n = size(S);
        string cur = ""; cur.reserve(n);
        dfs(S, cur, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& S, string& cur, int i, int cnt) {
        if(i == n) {
			// if valid, update ans to store maximum good person found till now
            if(valid(S, cur)) ans = max(ans, cnt);
            return;
        }
        cur.append(1, '0');
        dfs(S, cur, i+1, cnt);        // assuming ith person is bad
        cur.back() = '1';
        dfs(S, cur, i+1, cnt + 1);    // assuming ith person is good
        cur.pop_back();        
    }
    bool valid(vector<vector<int>>& S, string& cur) {
        for(int i = 0; i < n; i++) 
            if(cur[i] == '1') 
                for(int j = 0; j < n; j++) 
                    if(S[i][j] != 2 && S[i][j] != cur[j] - '0') return false;
        return true;
    }
};