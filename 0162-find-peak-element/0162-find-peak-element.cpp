class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak=INT_MIN;
        int peak_index=0;
        if(nums.size()==1)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>peak)
            {
                peak=nums[i];
                peak_index=i;
            }
        } 
        return peak_index;
    }
    
};