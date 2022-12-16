class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum=0;
        int maxSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            curSum=curSum+nums[i];
            if(curSum > maxSum)
            {
                maxSum=curSum;
            }
            if(curSum < 0)
            {
                curSum =0;
            }
        }
        
        int negativeSum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > negativeSum)
            {
                negativeSum=nums[i];
            }
        }
        if(maxSum==0)
            return negativeSum;
        else
            return maxSum;
        
    }
};