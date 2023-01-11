class Solution {
public:
    int rev(int n)  
    {
        int res=0;
        while(n!=0)
        {
            res=res*10+n%10;
            n/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> um;   
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i]-rev(nums[i]);        
            um[tmp]++;
            res=(res+um[tmp]-1)%1000000007;      
        }
        return res%1000000007;
    }
};