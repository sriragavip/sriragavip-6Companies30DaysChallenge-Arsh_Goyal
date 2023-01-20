class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> hash;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto& a: edges){
            hash[a[0]].push_back({a[1], a[2]});
            hash[a[1]].push_back({a[0], a[2]});
        }
        int result = 1e9, ans = -1;
        for(int i = 0; i < n; i++){
            int found = dijkstra(i, n, distanceThreshold);
            if(found <= result)
                result = found, ans = i;
        }
        return ans;
    }
    int dijkstra(int& i, int& n, int& dt){
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            for(auto& a: hash[node]){
                int b = cost + a.second;
                if(dist[a.first] > b){
                    dist[a.first] = b;
                    pq.push({b, a.first});
                }
            }
        }
        int count = 0;
        for(int j = 0; j < n; j++)
            count += dist[j] <= dt;
        return count;
    }
};