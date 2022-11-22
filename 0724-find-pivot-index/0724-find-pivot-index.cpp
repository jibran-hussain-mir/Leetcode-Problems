class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
       // Brute Force Approach O(n2)
//         for(int i=0;i<nums.size();i++)
//         {
//             int sumLeft=0,sumRight;
//             sumLeft=sumRight=0;
//             for(int j=0;j<i;j++)
//             {
//                 sumLeft=sumLeft+nums[j];
//             }
//             for(int k=i+1;k<nums.size();k++)
//             {
//                 sumRight=sumRight+nums[k];
//             }
//             if(sumLeft==sumRight)
//             {
//                 return i;
                
//             }
//         }
//         return -1;
        
       // O(n) Discuss Section
        int sumRight=accumulate(nums.begin(),nums.end(),0);
        int sumLeft=0;
        for(int i=0;i<nums.size();i++)
        {
            sumRight-=nums[i];
            if(sumLeft==sumRight) return i;
            sumLeft+=nums[i];
        }
        return -1;
    }
};