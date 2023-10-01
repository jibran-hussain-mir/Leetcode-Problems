class Solution {
public:
    int count(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == triangle.size()-1 ) return triangle[i][j];
        if(i >= triangle.size() || j >= triangle[i].size()) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + count(i+1,j,triangle,dp);
        int diagonal = triangle[i][j] + count(i+1,j+1,triangle,dp);
        
        return dp[i][j]=min(down,diagonal);
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return count(0,0,triangle,dp);
    }
};