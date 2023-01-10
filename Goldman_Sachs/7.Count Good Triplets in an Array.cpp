class Solution {
private:
    int tree[400004];
public:
    void update(int low, int high, int parent, int val){
        if(low>val || high<val){
            return;
        }
        if(low==val && high==val){
            tree[parent]=1;
            return;
        }
        int mid=(low+high)/2;
        update(low,mid,2*parent+1,val);
        update(mid+1,high,2*parent+2,val);
        tree[parent]=tree[2*parent+1]+tree[2*parent+2];
    }
    
    int findMinCount(int low, int high, int parent, int lowerR, int higherR){
        if(low>higherR || high<lowerR){
            return 0;
        }
        if(low>=lowerR && high<=higherR){
            return tree[parent];
        }
        int mid=(low+high)/2;
        return findMinCount(low,mid,2*parent+1,lowerR,higherR)+findMinCount(mid+1,high,2*parent+2,lowerR,higherR);
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        memset(tree,0,sizeof(tree));
        int n=nums1.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums1[i]]=i;
            nums1[i]=i;
        }
        for(int i=0;i<n;i++){
            nums2[i]=mpp[nums2[i]];  
        }
        update(0,n-1,0,nums2[0]); 
        long long res=0;
        for(int i=1;i<n-1;i++){
            long long int countLessThanE=findMinCount(0,n-1,0,0,nums2[i]-1); 
            long long int biggerElements=(n-1)-nums2[i];  
            int leftOutBiggerElements=i-countLessThanE;  
            long long int biggerElementOnRightSide=biggerElements-leftOutBiggerElements;
            res+=(countLessThanE*biggerElementOnRightSide);
            update(0,n-1,0,nums2[i]);  
        }
        return res;
    }
};