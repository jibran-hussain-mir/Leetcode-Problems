class Solution {
public:
    int getPivot(vector<int>& nums){
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid] >= nums[0])
            {
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    
    int binarySearch(vector<int>&nums,int target,int start,int end)
    {
        int s=start;
        int e=end;
        while(s<=e)
        {
            int mid=e+(s-e)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=getPivot(nums);
        if(target >= nums[pivot] && target <= nums[nums.size()-1])
            return binarySearch(nums,target,pivot,nums.size()-1);
        else 
            return binarySearch(nums,target,0,pivot-1);
    }
};