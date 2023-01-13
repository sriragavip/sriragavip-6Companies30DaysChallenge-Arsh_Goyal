class Solution {
public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
        int nc=0,sn=INT_MAX;
        long long res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=res+abs(matrix[i][j]);
                abs(sn)>abs(matrix[i][j])?sn=matrix[i][j]:sn=sn;
                if(matrix[i][j]<0){
                    nc++;
                }
            }
        }
        if(nc%2!=0){
            res-=2*abs(sn);
        }
        return res;
    }
};