class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    int sum=0;
    void f(int index,vector<int>&v,int k,int n){
      if(index>=v.size()){
        if(sum==n and temp.size()==k){
          ans.push_back(temp);
        }
        return;
      } 
      if(sum>n) return;
      
      temp.push_back(v[index]);
      sum+=v[index];
      f(index+1,v,k,n);
      temp.pop_back();
      sum-=v[index];
      f(index+1,v,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int>v;
      for(int i=1;i<=9;i++){
        v.push_back(i);
      }
      f(0,v,k,n);
      return ans;
    }
};