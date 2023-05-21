//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool checkIfBipartite(vector<int>adj[],vector<int>& colour,queue<int> q,int node)
        {
            q.push(node);
            if(colour[node] == -1) colour[node]=0;
            while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto adjacentNode: adj[node])
                        {
                            if(colour[adjacentNode] != -1 && colour[adjacentNode] == colour[node])
                                return false;
                            
                           else if(colour[adjacentNode] == -1)
                                {
                                    colour[adjacentNode]=!colour[node];
                                    q.push(adjacentNode);
                                }
                        }
                }
            return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colour(V,-1);
	    queue<int> q;
	    
	    for(int i=0;i<V;i++)
	        {
	            if(colour[i] == -1)
	                if(checkIfBipartite(adj,colour,q,i) == false) return false;
	        }
	       return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends