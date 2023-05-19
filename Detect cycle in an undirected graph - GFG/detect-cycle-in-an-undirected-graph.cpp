//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detectCycle(vector<int> adj[],vector<int> &visited,queue<pair<int,int>> q,int node){

        q.push({node,-1});
        visited[node]=1;
        while(!q.empty())
            {
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto adjacentNode: adj[node])
                    {
                        if(!visited[adjacentNode])
                            {
                                q.push({adjacentNode,node});
                                visited[adjacentNode]=1;
                            }
                        else if(parent != adjacentNode)
                            {
                                return true;
                            }
                    }
            }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        queue<pair<int,int>> q;
       
        
        for(int i=0;i<V;i++)
            {
                if(!visited[i])
                    {
                        if(detectCycle(adj,visited,q,i) == true)
                            return true;
                    }
            }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends