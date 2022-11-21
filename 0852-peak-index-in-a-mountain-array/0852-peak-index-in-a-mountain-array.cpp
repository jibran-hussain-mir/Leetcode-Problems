class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // O(n) : Linear Search
        // for(int i=0;i<arr.size()-1;i++)
        //     {
        //         if(arr[i] > arr[i+1])
        //         {
        //             return i;
        //         }
        //     }
        // return -1;

        // O(logn) : Binary Search

        int s=0;
        int e=arr.size()-1;
        while(s<e)
            {
                int mid=s+(e-s)/2;
                if(arr[mid] < arr[mid+1])
                    {
                        s=mid+1;
                    }
                else{
                    e=mid;
                }
            }
            return e;
    }
};