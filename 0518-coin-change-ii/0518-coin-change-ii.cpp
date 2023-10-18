class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // Tabulation
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) 
                dp[0][j] = 1;
            else 
                dp[0][j] = 0;
        }

        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = dp[index - 1][target];
                int take = 0;

                if (target >= coins[index])
                    take = dp[index][target - coins[index]];

                dp[index][target] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};
