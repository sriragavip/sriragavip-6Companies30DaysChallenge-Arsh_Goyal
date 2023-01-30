class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,unsigned long long> viewcount;
        unordered_map<string,pair<string,unsigned long>> max_id;
        vector<vector<string>> ans;
        unsigned long  max_views=0;
        int n=creators.size();
        for(int i=0;i<n;i++){
            //counting total views of each creator
            viewcount[creators[i]]=viewcount[creators[i]]+views[i];
            //finding max views
            if(max_views<viewcount[creators[i]]){
                max_views=viewcount[creators[i]];
            }
            //finding creators id with max views and lexicographically smallest
            if(max_id.find(creators[i])==max_id.end()){
                max_id[creators[i]]=make_pair(ids[i],views[i]);
            }
            else if(max_id[creators[i]].second<views[i]){
                max_id[creators[i]]=make_pair(ids[i],views[i]);
            }
            else if(max_id[creators[i]].second==views[i]){
                if(max_id[creators[i]].first>ids[i]){
                   max_id[creators[i]].first=ids[i]; 
                }
            }

        }
        //finding ans;
        for(auto i:viewcount){
            if(max_views==i.second){
                ans.push_back({i.first,max_id[i.first].first});
            }
        }
        return ans;
    }
};