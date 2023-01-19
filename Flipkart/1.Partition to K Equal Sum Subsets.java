class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }

        if(sum%k!=0 || nums.length<k) return false;

        Arrays.sort(nums);
        return canPartitionKSubsets(nums,sum/k,nums.length-1,new int[k]);
    
    }
    public boolean canPartitionKSubsets(int a[],int target,int i,int bucket[]){

        if(i==-1)
            return true;

        for(int j=0;j<bucket.length;j++){

            if(bucket[j]+a[i]<=target){
                bucket[j]+=a[i];
                if(canPartitionKSubsets(a,target,i-1,bucket))
                    return true;
                bucket[j]-=a[i];
            
            }
            if(bucket[j]==0)
                break;
        
        }
        return false;
    
    }
}