class Solution {
public:
    int trailingZeroes(int n) {
        int temp=n/5;
        int ans=0;
        ans+=temp;
        while(temp){
            ans+=(temp/5);
            temp=temp/5;
        }
        return ans;
    }
};