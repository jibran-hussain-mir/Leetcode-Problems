//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        // Approach 1
        int count_zero=0,count_one=0;
        for(int i=0;i<n;i++)
            {
                if(arr[i]==0) count_zero++;
                else count_one++;
            }
        for(int i=0;i<count_zero;i++)
            {
                arr[i]=0;
            }
        for(int j=count_zero;j<n;j++)
            {
                arr[j]=1;
            }
        
        // Approach 2
        // sort(arr.begin(),arr.end()); Not Working
        
        // Approach 3 (Two Pointer Approach)
        // int i=0,j=n-1;
        // while(i<j)
        // {
        //     while(arr[i]==0 && i<j)
        //     {
        //         i++;
        //     }
        //     while(arr[j]==1 && i<j)
        //     {
        //         j++;
        //     }
        //     if(i<j)
        //         {
        //             swap(arr[i],arr[j]);
        //             i++;
        //             j--;
        //         }
        // }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends