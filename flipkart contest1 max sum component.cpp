class Solution{   
public:

    long long dfs(int u,vector<int> &visited,vector<vector<int>> &adj,vector<int> &values){
        visited[u]=1;
        // cout<<u;
        long long maxi=values[u-1];
        for(auto v:adj[u]){
            if(visited[v]==0){
                maxi+=dfs(v,visited,adj,values);
            }
        }
        return maxi;
    }

    long long solve(int V,int E,vector<int> values,vector<vector<int>> edges){
      //code here
    //   map<int,vector<int>> adj;
      vector<vector<int>> adj(V+1);
      for(int i=0;i<E;i++){
          adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
      }
      long long ans=0;
      vector<int> visited(V+1,0);
      for(int i=1;i<=V;i++){
          if(visited[i]==0){
              long long maxi=dfs(i,visited,adj,values);
              ans=max(ans,maxi);
            //   cout<<endl;
          }
        }
        
        return ans;
    }
};