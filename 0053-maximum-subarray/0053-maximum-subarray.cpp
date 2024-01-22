class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0],max=0;
        
        for(int i=0;i<nums.size();i++){
            max += nums[i];
            if(max > maxi) maxi=max;
            if(max < 0) max=0;
        }
        return maxi;
    }
};