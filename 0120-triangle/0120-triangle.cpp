class Solution {
public:
//     Tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),-1));        
        for(int j=0;j<=n-1;j++){
                dp[n-1][j]= triangle[n-1][j];
            }
        int firstop=1000, secondop=1000;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                 firstop=triangle[i][j] + dp[i+1][j];
                 secondop= triangle[i][j]  + dp[i+1][j+1];
                 dp[i][j] = min(firstop,secondop);
            }
        }
        return dp[0][0];
    }
};