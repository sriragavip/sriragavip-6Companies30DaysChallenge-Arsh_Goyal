class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int>pq;
        vector<pair<int,int>>v; 
        for(int i = 0;i<Capital.size();i++){
            v.push_back({Capital[i],i});
        }
        sort(v.begin(),v.end());
        int ans = W;
        int j = 0;
        while(k){
            while(j<Capital.size() && v[j].first<=W){
                pq.push(Profits[v[j].second]);
                j++;
            }
            if(!pq.empty()){
                ans+=pq.top();
                W = W+pq.top();
                pq.pop();
            }
             k--;
        }
        return ans;
    }
};