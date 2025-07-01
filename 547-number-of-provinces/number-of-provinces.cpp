class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited)
    {
        visited[node]=1;
        for (int neighbour:adj[node])
            if (!visited[neighbour])
                dfs(neighbour,adj,visited);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),count=0;
        vector<vector<int>> adj(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                if (isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        vector<int> visited(n,0);
        for (int i=0;i<n;i++)
            if (!visited[i])
            {
                dfs(i,adj,visited);
                count++;
            }
        return count;
    }
};