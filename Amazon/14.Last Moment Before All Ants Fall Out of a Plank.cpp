class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxleft = 0;
        int minright = INT_MAX;
        for(auto it:left)maxleft = max(it,maxleft);
        for(auto it:right)minright = min(it,minright);

        return max(maxleft,n-minright);
    }
};