class Solution {
public:
    int count(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
       int left=count(n-1,dp);
       int right=count(n-2,dp);
        
        return dp[n]=left+right;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
    }
};