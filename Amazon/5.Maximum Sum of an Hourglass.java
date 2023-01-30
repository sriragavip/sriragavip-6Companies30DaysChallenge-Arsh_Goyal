class Solution {
    public int maxSum(int[][] grid) {

        int result=0;
       
        for(int i=0;i<grid.length-2;i++){
            for(int j=0;j<grid[0].length-2;j++){
                int temp = grid[i+1][j+1];
                for(int k = 0; k < 3; k++){
                    temp += grid[i][j+k];
                    temp += grid[i+2][j+k];
                }
                result = Math.max(result, temp);
            }
        }

        return result;
        
    }
}