class Solution {
public:
    int result(vector<int> & nums,int index,int target,vector<vector<int>> &dp){
        
        if(target == 0) return true;
        if(index == 0) return nums[0] == target;
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int notPick = result(nums,index-1,target,dp);
        int pick=0;
        if(target >= nums[index])  pick = result(nums,index-1,target-nums[index],dp);
        
        return dp[index][target]=notPick | pick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        cout<<sum/2<<endl;
        if(sum % 2 != 0) return false;
                vector<vector<int>> dp(nums.size(),vector<int>(sum/2 +1,-1));

        
        return result(nums,nums.size()-1,sum/2,dp);
    }
};