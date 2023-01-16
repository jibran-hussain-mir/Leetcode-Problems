class Solution {
public:
    
    vector<int> prevSmaller(vector<int> arr,int n)
    {
        stack<int> st;
        vector<int> v(n);
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            
            while(st.top()!= -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    
    vector<int> nextSmaller(vector<int> arr,int n)
    {
        stack<int> st;
        vector<int> v(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            
            while(st.top()!= -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=INT_MIN;
        
        vector<int> next(n);
        vector<int> previous(n);
        next=nextSmaller(heights,n);
        previous=prevSmaller(heights,n);
             
      
        
        for(int i=0;i<n;i++)
        {
            int length=heights[i];
            if(next[i] == -1)
            {
                next[i]=n;
            }
            
            int breadth=next[i]-previous[i]-1;
            int currArea=length*breadth;
            area=max(area,currArea);
        }
        return area;
        
    }
};