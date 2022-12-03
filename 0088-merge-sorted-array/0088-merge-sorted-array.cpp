class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        
        vector<int> v;
        
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else if(nums2[j] <nums1[i])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else{
                v.push_back(nums1[i]);
                v.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        
        for(;j<n;j++)
            v.push_back(nums2[j]);
        for(;i<nums1.size();i++)
            v.push_back(nums1[i]);
        
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=v[i];
        }
    }
    
};