class Solution {    
public:
    int maxWays(int index,int target,vector<int>& denominations,vector<vector<int>> &dp){
    // Base Case
    if(target == 0 ) return 1;
    if(index == 0 ){
        if(target % denominations[0] == 0) return 1;
        return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    // Total Possibilities
    int notTake = maxWays(index-1,target,denominations,dp);
    int take = 0;
    if(target >= denominations[index]) take = maxWays(index,target-denominations[index],denominations,dp);

    return dp[index][target]=take + notTake;
}
    
    int change(int amount, vector<int>& coins) {
         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return maxWays(coins.size()-1,amount,coins,dp);
    }
};