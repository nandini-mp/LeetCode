class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>& colours)
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            for (int neighbour:graph[node])
            {
                if (colours[neighbour]==-1)
                {
                    colours[neighbour]=1-colours[node];
                    q.push(neighbour);
                }
                else if (colours[neighbour]==colours[node])
                    return false;                   
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colours(n,-1);
        for (int i=0;i<n;i++)
        {
            if (colours[i]==-1)
            {
                colours[i]=0;
                if (!bfs(i,graph,colours)) return false;
            } 
        }
        return true;
    }
};

/*
class Solution {
public:
    bool dfs(int node,int colour,vector<vector<int>>& graph,vector<int>& colours)
    {
        colours[node]=colour;
        for (int neighbour:graph[node])
        {
            if (colours[neighbour]==-1)
            {
                if (!dfs(neighbour,1-colour,graph,colours)) return false;
            }
            else if (colours[neighbour]==colour)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colours(n,-1);
        for (int i=0;i<n;i++)
        {
            if (colours[i]==-1)
                if (!dfs(i,0,graph,colours)) return false;
        }
        return true;
    }
};
*/