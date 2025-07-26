class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for (auto& edge:times)
            adjList[edge[0]-1].push_back({edge[1]-1,edge[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[k-1]=0;
        pq.push({0,k-1}); //{distance,node}
        while (!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (distance>dist[node]) continue;
            for (auto& it:adjList[node])
            {
                int neighbour=it.first;
                int wt=it.second;
                if (dist[neighbour]>distance+wt)
                {
                    dist[neighbour]=distance+wt;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        int ans=INT_MIN,flag=0;
        for (int i=0;i<n;i++)
        {
            ans=max(ans,dist[i]);
            if (dist[i]==1e9)
            {
                flag=1;
                break;
            }
        }
        return flag==1?-1:ans;
    }
};