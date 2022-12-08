//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    char toLowerCase(char ch)
        {
            if(ch >= 'a' && ch <='b')
                return ch;
            else
                return ch-'A'+'a';
            
        }
        char max(vector<int> arr)
            {
                int maxIndex=0;
                int i=0;
                for(i=1;i<arr.size();i++)
                    {
                        if(arr[i] > arr[maxIndex])
                            {
                                maxIndex=i;
                                
                            }
                            
                    }
                    
                    return 'a'+maxIndex;
            }
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        vector<int> arr(25,0);
        int i=0;
       for(int i=0;i<str.length();i++)
        {
            int index=str[i]-'a';
                arr[index]++;
        }
            
        return max(arr);
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends