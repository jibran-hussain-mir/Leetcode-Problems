//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
        
    bool knows(vector<vector<int> >& M,int a, int b, int n)
        {
            if(M[a][b] == 1)
                return true;
            return false;
        }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++)
            {
                st.push(i);
            }
        
        while(st.size() > 1)
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                if(knows(M,a,b,n))
                    {
                        st.push(b);
                    }
                else{
                    st.push(a);
                }
            }
            
        int celebrity=st.top();
        
        // Row Check
        int rowCheck=false;
        int zeroCount=0;
            
        for(int i=0;i<n;i++)
            {
                if(M[celebrity][i] == 0)
                    zeroCount++;
            }
            if(zeroCount == n) rowCheck=true;
            
        // Column Check
        int columnCheck=false;
        int oneCount=0;
            
        for(int i=0;i<n;i++)
            {
                if(M[i][celebrity] == 1)
                    oneCount++;
            }
            if(oneCount == n-1) columnCheck=true;
            
            if(rowCheck && columnCheck)
                return celebrity;
            else return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends