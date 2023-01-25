class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& s) {
    sort(s.begin(), s.end());
    int ans=s[0]-b;
    for(int i=1;i<s.size();i++){   
        int x=s[i]-s[i-1]-1;
        ans=max(ans, x);
    }
    ans=max(ans, t-s[s.size()-1]);
    return ans;
}
};