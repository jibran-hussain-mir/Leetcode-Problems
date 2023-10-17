class Solution {

    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> pre(amount+1,0),curr(amount+1,0);
//         Tabulation Code
        for(int j=0;j<=amount;j++){
            if(j % coins[0] == 0) pre[j]=j/coins[0];
            else pre[j] =1e9;
        }
        
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int notTake=pre[target];
                int take= INT_MAX;
                if(coins[index] <= target){
                     take =1+ curr[target-coins[index]];
              }
                curr[target]=min(take,notTake);
            }
            pre=curr;
        }
        int ans= pre[amount];
         if(ans >= 1e9 ) return -1;
        return ans;
    }
};