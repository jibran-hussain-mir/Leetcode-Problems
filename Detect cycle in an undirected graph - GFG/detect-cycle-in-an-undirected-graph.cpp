//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private: 
    bool detectCycle(vector<int> adj[],vector<int> &visited,int parent,int node)
        {
            visited[node]=1;
            for(auto adjacentNode:adj[node])
                {
                    if(!visited[adjacentNode])
                        {
                            if(detectCycle(adj,visited,node,adjacentNode)) return true;
                        }
                    else if(parent != adjacentNode)
                        return true;
                }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        int initialNodeParent=-1;
        for(int i=0;i<V;i++)
            {
                if(!visited[i])
                    {
                        if(detectCycle(adj,visited,initialNodeParent,i)) return true;
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