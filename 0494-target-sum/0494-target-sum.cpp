class Solution {
public:
    int countWays(int index,int target,vector<int> &nums){
        if(index == 0){
          return (target - nums[0] == 0) + (target + nums[0] == 0) ;
        }
        
        int one =  countWays(index-1,target+nums[index],nums);
      
        int two =  countWays(index-1,target - nums[index],nums);

        return one + two;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countWays(n-1,target,nums);
        
        
    }
};