class Solution:
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        return self.dfs(N, K, W, 0, {})
    
    def dfs(self, N, K, W, cur, memo):
        
        if cur >= K:
            return 1.0 if cur <= N else 0
        
        if cur in memo:
            return memo[cur]
        
        prob = 0
        
        for i in range(1, W+1):
            prob += self.dfs(N, K, W, cur+i, memo)
        
        prob /= W
        
        memo[cur] = prob
        
        return prob