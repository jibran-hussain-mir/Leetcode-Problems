class Solution {
public:
    int firstOccurance(vector<int>& arr,int target)
    {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid] > target)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    
    int lastOccurance(vector<int>& arr,int target)
    {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==target)
            {
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid] > target)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        
        
        // BRUTE FORCE APPROACH
//      vector<int> v;
//         int first=-1;int last = -1;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i] == target)
//             {
//                 if(first == -1)
//                 {
//                     first = i;
//                     last = i;
//                 }
//                 else
//                 {
//                     last = i;
//                 }
//             }
            
//         }
//         v.push_back(first);
//         v.push_back(last);
//         return v;
        vector<int> v;
       int first=firstOccurance(nums,target);
        int last=lastOccurance(nums,target);
       
        v.push_back(first);
        v.push_back(last);
        
        return v;
    }
};