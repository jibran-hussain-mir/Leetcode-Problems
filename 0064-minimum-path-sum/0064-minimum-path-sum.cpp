class Solution {
public:
//     Memoization
    
    int minPaths(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1000;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left=grid[i][j] + minPaths(i,j-1,grid,dp);
        int up= grid[i][j] + minPaths(i-1,j,grid,dp);
        
        return dp[i][j]=min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        
        return minPaths(i-1,j-1,grid,dp);
    }
};