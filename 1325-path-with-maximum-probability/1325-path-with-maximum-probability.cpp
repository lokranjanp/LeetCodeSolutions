class Solution {
public:
    const int MAXN = 1e4+5;
    typedef pair<double, int> p;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<p>adj[MAXN];
        int size = edges.size();

        for(int i = 0; i<size; ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            double cost = prob[i];
            adj[u].push_back({cost, v});
            adj[v].push_back({cost, u});
        }

        vector<double>res(MAXN);
        res[start] = 1.0;
        priority_queue<p>heap;

        heap.push({1.0, start});
        while(!heap.empty())
        {
            auto [cost, node] = heap.top();
            heap.pop();

            if(node == end)
                return cost;

            for(auto [adjcost, adjnode] : adj[node])
            {
                double newcost = cost * adjcost;
                if(newcost > res[adjnode])
                {
                    res[adjnode] = newcost;
                    heap.push({newcost, adjnode});
                }
            }
        }
        return 0.0;
    }
};