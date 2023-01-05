#define ll long long
#define pii pair<ll,ll>
class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adjList[n];

        for(auto i:roads){
            adjList[i[0]].push_back({i[1],i[2]});
            adjList[i[1]].push_back({i[0],i[2]});
        }

        vector<ll>dist(n,1e15);
        vector<ll>ways(n,0);

        dist[0]=0;
        ways[0]=1;

        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({dist[0],0});

        while(!pq.empty()){
            ll currDist=pq.top().first;
            ll currNode=pq.top().second;
            pq.pop();

            for(auto i:adjList[currNode]){
                ll newDist=currDist+i.second;

                if(newDist<dist[i.first]){
                    dist[i.first]=newDist;
                    ways[i.first]=ways[currNode];

                    pq.push({dist[i.first],i.first});
                }
                else if(newDist==dist[i.first]){
                    ways[i.first]=(ways[i.first]+ways[currNode])%mod;
                }
            }
        }
        return ways[n-1];
    }
};