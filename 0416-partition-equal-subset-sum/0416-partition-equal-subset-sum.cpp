class Solution {
public:

    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        cout<<sum/2<<endl;
        if(sum % 2 != 0 || nums.size() == 1) return false;

        
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum,false)); 
for(int row=0;row < nums.size();row++){
    dp[row][0]=true;
}
dp[0][nums[0]]=true;

for(int index = 1;index < nums.size();index++){
    for(int target=1;target<=sum/2;target++){
        bool notPick=dp[index-1][target];
        bool pick=false;
        if(target >= nums[index]) pick=dp[index-1][target-nums[index]];
        dp[index][target]= pick | notPick;
    }
}

return dp[nums.size()-1][sum/2];
    }
};




