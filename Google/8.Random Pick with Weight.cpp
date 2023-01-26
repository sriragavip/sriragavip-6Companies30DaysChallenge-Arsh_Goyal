class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            v.push_back(v[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int n= rand()%v[v.size()-1];
        auto it=upper_bound(v.begin(),v.end(),n);
        return it-v.begin();
    }
};