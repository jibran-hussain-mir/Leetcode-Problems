class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
//         This code is also working---but more code
        // int i,j;
        // i=j=0;
        
        // while(j<nums.size())
        // {
        //     if(nums[i]==0 && nums[j]==0)
        //     {
        //         j++;
        //     }
        //     else if(nums[i]==0 && nums[j] != 0)
        //     {
        //         swap(nums[i],nums[j]);
        //         i++;
        //         j++;
        //     }
        //     else if(nums[i] != 0 && nums[j] == 0)
        //     {
        //         i++;
        //         j++;
        //     }
        //    else{
        //        i++;
        //        j++;
        //    }
        // }
        
//         Solution with less code
       
        int i,j;
        i=j=0;
        
        while(i<nums.size())
        {
            if(nums[i] != 0)
            {
                swap(nums[j],nums[i]);
                j++;
            }
            i++;
        }
    }
};