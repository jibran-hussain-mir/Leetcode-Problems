//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> indegree(N);
	    vector<vector<int>> adjMatrix(N);
	    
	    for(int i=0;i<prerequisites.size();i++)
	        {
	            adjMatrix[prerequisites[i].first].push_back(prerequisites[i].second);
	        }
	    for(int i=0;i<N;i++)
	        {
	            for(auto it: adjMatrix[i])
	                {
	                    indegree[it]++;
	                }
	        }
	   queue<int> q;
	   int count=0;
	   for(int i=0;i<indegree.size();i++)
	    {
	        if(indegree[i] == 0)
	            {
	                q.push(i);
	            }
	    }
	    
	    while(!q.empty())
	        {
	            count++;
	            int node=q.front();
	            q.pop();
	            for(auto it:adjMatrix[node])
	                {
	                    indegree[it]--;
	                    if(indegree[it] == 0 )
	                        {
	                            q.push(it);
	                        }
	                }
	        }
	       if(count == N) return true;
	      return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends