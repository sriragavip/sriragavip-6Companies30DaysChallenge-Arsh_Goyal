class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
        vector<int> min_a(n,INT_MAX); 
        vector<int> max_a(n,INT_MIN);
        
        for(int i=1;i<n-1;i++){  
            min_a[i]=min(min_a[i-1],nums[i-1]);
        }
        
        for(int i=n-2;i>0;i--){    
            max_a[i]=max(nums[i+1],max_a[i+1]);
        }
        
        for(int i=1;i<n-1;i++){   
            if(min_a[i]<nums[i]&&nums[i]<max_a[i])
                return true;
        }
            return false;
    }
};