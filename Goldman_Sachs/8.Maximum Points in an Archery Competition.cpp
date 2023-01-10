class Solution {
public:
    void recur(int &sum, vector<int>&v , int n , int ind ,vector<int>given, vector<int>&ans ,int curr_sum){
        if(ind<0){
            if(curr_sum>sum){
                sum=curr_sum;
                v[0]+=n;
                ans=v;
            }
            return;
        }
        if(n-(given[ind]+1)>=0){
            v[ind]=given[ind]+1;
            n-=(given[ind]+1);
            curr_sum+=ind;
            recur(sum,v,n,ind-1,given,ans,curr_sum);
            v[ind]=0;
            n+=(given[ind]+1);
            curr_sum-=ind;
        }
        recur(sum,v,n,ind-1,given,ans,curr_sum);
    }
    vector<int> maximumBobPoints(int n, vector<int>& aliceArrows) {
        vector<int>v(12,0) , ans;
        int sum=0;
        sum=0;
        int c=0;
        recur(sum,v,n,11,aliceArrows,ans,c);
        return ans;
    }
};