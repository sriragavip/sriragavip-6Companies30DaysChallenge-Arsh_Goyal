class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0,i=0,j=piles.size()-2;
        for(;j>i;j=j-2)
            i++,sum+=piles[j];
        return sum;
    }
};