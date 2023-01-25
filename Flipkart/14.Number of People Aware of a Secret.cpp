#define ll long long int
ll m=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> vec(n,0);
        vec[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+delay;j<i+forget && j<n ;j++)
            {
                vec[j]=(vec[j]%m+vec[i]%m)%m;
            }
        }
        ll ans=0;
        for(int i=n-forget;i<n;i++)
        {
            ans=(ans%m+vec[i]%m)%m;
        }
        return ans;
    }
};