class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < n - 1; ++i) 
            graph[i].push_back({i + 1, 1});
        
        vector<int> answer;
    
        auto dijkstra = [&]() {
            vector<int> dist(n, numeric_limits<int>::max());
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        

            dist[0] = 0;
            pq.push({0, 0}); 
        
            while (!pq.empty()) {
                int distance = pq.top().first;
                int city = pq.top().second;
                pq.pop();
            
                if (distance > dist[city]) continue;
            
                for (auto& neighbor : graph[city]) {
                    int nextCity = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[city] + weight < dist[nextCity]) {
                        dist[nextCity] = dist[city] + weight;
                        pq.push({dist[nextCity], nextCity});
                    }
                }
            }

        return dist[n - 1];
    };
    

    for (auto& query : queries) 
    {
        int u = query[0];
        int v = query[1];
        graph[u].push_back({v, 1}); 
        int shortestPathLength = dijkstra(); 
        answer.push_back(shortestPathLength);
    }
    
    return answer;
    }
};