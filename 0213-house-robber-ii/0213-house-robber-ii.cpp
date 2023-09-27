class Solution {
public:
    int result(vector<int>& nums){
        int n=nums.size();
    int prev2=0,prev1=nums[0];
    for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i > 1){
                pick=nums[i]+ prev2;
            }
            int notPick=prev1;
            int curr=max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size() == 1) return nums[0];
       for(int i=0;i<nums.size();i++)
       {
        if(i!=0) temp1.push_back(nums[i]);
        if(i != nums.size()-1) temp2.push_back(nums[i]);
       }
        return max(result(temp1),result(temp2));
    }
};