class Solution {
public:
    int minimumCardPickup(vector<int>&s) {
       int maxi = INT_MAX;
       unordered_map<int,int>mpp;
       int n = s.size();
       for(int i = 0; i < n; ++i)
       {   

           if(mpp.find(s[i]) != mpp.end())  maxi = min(maxi, i-mpp[s[i]]+1);
             mpp[s[i]] = i;
       }
      if(maxi == INT_MAX) return -1;
      return maxi;
    }
};