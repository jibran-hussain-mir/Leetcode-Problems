//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void findIslandsCount(vector<vector<int>>& grid, int visited[][1000], int rown, int coln, set<vector<pair<int,int>>>& s)

        {
             int rowSize=grid.size();
             int colSize=grid[0].size();
            queue<pair<int,int>> q;
            q.push({rown,coln});
            visited[rown][coln]=1;
            vector<pair<int,int>> v;
            v.push_back({0,0});
            while(!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    
                    int rowcords[4]={0,0,-1,+1};
                    int colcords[4]={+1,-1,0,0};
                    
                    for(int i=0;i<4;i++)
                        {
                           int nrow=row+rowcords[i];
                           int ncol=col+colcords[i];
                            
                           if((nrow >=0 && nrow < rowSize) && (ncol >=0 && ncol < colSize) && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
                                {
                                    visited[nrow][ncol]=1;
                                    q.push({nrow,ncol});
                                    v.push_back({nrow-rown,ncol-coln});
                                }
                        }
                }
            s.insert(v);
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int rowSize=grid.size();
        int colSize=grid[0].size();
        int visited[rowSize][1000]={0};
        int islandCount=0;
        set<vector<pair<int,int>>> s;
        for(int i=0;i<rowSize;i++)
            {
                for(int j=0;j<colSize;j++)
                    {
                        if(grid[i][j] == 1 && !visited[i][j])
                            {
                                
                                findIslandsCount(grid,visited,i,j,s);
                            }
                    }
            }
            
            
            return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends