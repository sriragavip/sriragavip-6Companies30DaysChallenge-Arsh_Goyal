class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    set<int> sorted;
    queue<int> sources;
    
    for(auto& p: prerequisites){
        graph[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }
    
    for(int i = 0; i < numCourses; i++){
        if(inDegree[i] == 0){
            sources.push(i);
        }
    }
    
    while(!sources.empty()){
        int curr = sources.front();
        sources.pop();
        sorted.insert(curr);
        for(auto nig: graph[curr]){
            inDegree[nig]--;
            if(inDegree[nig] == 0){
                sources.push(nig);
            }
        }
    }
    
    return sorted.size() == numCourses;
    
}
};