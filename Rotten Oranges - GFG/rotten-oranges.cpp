//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int visited[grid.size()][grid[0].size()];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                    {
                        if(grid[i][j] == 2)
                            {
                                q.push({{i,j},0});
                                visited[i][j]=2;
                            }
                        else visited[i][j]=0;
                    }
            }
        int tm=0;
        while(!q.empty())
            {
                int row=q.front().first.first;
                int col=q.front().first.second;
                int t=q.front().second;
                q.pop();
                tm=max(tm,t);
                
                if((row - 1 >= 0 && row -1 < grid.size()) && (col >=0 && col < grid[0].size()) && grid [row-1][col] == 1 && visited[row-1][col] != 2)
                    {
                        q.push({{row-1,col},t+1});
                        visited[row-1][col] = 2;
                    }
                    
                if((row + 1 >= 0 && row +1 < grid.size()) && (col >=0 && col < grid[0].size()) && grid [row+1][col] == 1 && visited[row+1][col] !=2)
                    {
                        q.push({{row+1,col},t+1});
                        visited[row+1][col] = 2;
                    }
                    
                if((row >= 0 && row < grid.size()) && (col - 1 >=0 && col-1 < grid[0].size()) && grid [row][col-1] == 1 && visited[row][col-1] != 2)
                    {
                        q.push({{row,col-1},t+1});
                        visited[row][col-1] = 2;
                    }
                
                if((row >= 0 && row < grid.size()) && (col + 1 >=0 && col+ 1 < grid[0].size()) && grid [row][col+1] == 1 && visited[row][col+1] != 2)
                    {
                        q.push({{row,col+1},t+1});
                        visited[row][col+1] = 2;
                    }
            }
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                    {
                       if(visited[i][j] != 2 && grid[i][j] == 1)
                        {
                            return -1;
                        }

                    }
            }
        return tm;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends