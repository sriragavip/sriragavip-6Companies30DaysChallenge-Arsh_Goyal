
class Solution {
public:
    bool find(int prev,int dst,int src,vector<int>&path_bob,vector<int>adj[]){
        if(src==dst){
            return true;
        }
        for(int i=0;i<adj[src].size();i++){
            if(prev!=adj[src][i]){
                path_bob.push_back(adj[src][i]);
                if(find(src,dst,adj[src][i],path_bob,adj))
                    return true;
                path_bob.pop_back();
            }
        }
        return false;
    }
    void dfs(int i,vector<int>&amount,int prev,int src,int &ans,vector<int>&path_bob,int curr,vector<int>adj[]){

        if(i==path_bob.size()){
            curr+=amount[src];
            int temp=amount[src];
            amount[src]=0;
            
            for(int k=0;k<adj[src].size();k++){
                if(prev!=adj[src][k]){
                    dfs(i,amount,src,adj[src][k],ans,path_bob,curr,adj);
                }
            }
            if(adj[src].size()==1&&adj[src][0]==prev){
                ans=max(ans,curr);
            }
            amount[src]=temp;
            return;
        }
        curr+=amount[src]/2;
        if(path_bob[i]!=src){
            curr+=amount[src]/2;
        }
        
        int temp=amount[src],temp2=amount[path_bob[i]];
        amount[src]=0;
        amount[path_bob[i]]=0;
        for(int k=0;k<adj[src].size();k++){
            if(prev!=adj[src][k]){
                dfs(i+1,amount,src,adj[src][k],ans,path_bob,curr,adj);
            }
        }
        if(adj[src].size()==1&&adj[src][0]==prev){
            ans=max(ans,curr);
        }
        amount[src]=temp;
        amount[path_bob[i]]=temp2;
    
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int> adj[n];
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> path_bob;
        path_bob.push_back(bob);
        find(-1,0,bob,path_bob,adj);
        int ans=INT_MIN;
        dfs(0,amount,-1,0,ans,path_bob,0,adj);
        return ans;
    }
};