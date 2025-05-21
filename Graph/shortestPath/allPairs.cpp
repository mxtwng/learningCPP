#include "shortestPath.h"
#include <vector>
#include <climits>
#include <queue>


//works with negative, detects neg cycle, dense graph, O(V^3)
void floydWarshall(int V, std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<std::vector<int>>  distance(V, std::vector<int> (V, INT_MAX));

    for (int u = 0; u < V; u++) {
        distance[u][u] = 0;
        for (const auto& [v, w] : adjList[u])
            distance[u][v] = w;
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);

    for (int i = 0; i < V; i++)
        if (distance[i][i] < 0)
            return; //check neg cycle
}

//works with neg, no neg cycle, O(V*E*logV) better than floyd for sparse graph
bool johnson(int V, std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<std::tuple<int, int, int>> edges;

    for (int u = 0; u < V; u++)
        for (const auto& [v, w] : adjList[u])
            edges.emplace_back(u, v, w); //basically the same as push_back({u, v, w})
    
    //adding dummy nodes
    std::vector<int> h (V + 1, INT_MAX);
    h[V] = 0;
    for (int u = 0; u < V; u++)
        edges.emplace_back(V, u, 0);

    //bellmanFord
    for (int i = 0; i < V; i++)
        for (const auto& [u, v, w] : edges)
            if (h[u] != INT_MAX && h[u] + w < h[v])
                h[v] = h[u] + w;

    //negcycle check
    for (auto [u, v, w] : edges)
        if (h[u] != INT_MAX && h[u] + w < h[v])
            return false;

    //reweight graph
    std::vector<std::vector<std::pair<int, int>>> newAdj;
    for (int u = 0; u < V; u++)
        for (const auto& [v, w] : adjList[u])
            newAdj[u].emplace_back(v, w + (h[u] - h[v]));
    //dijkstra for each node
    std::vector<std::vector<int>> distance (V, std::vector<int> (V, INT_MAX));
    for (int src = 0; src < V; src++) {
        distance[src][src] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({src, 0});
        while(!pq.empty()) {
            auto [u, d] = pq.top(); pq.pop();
            if (d > distance[src][u]) continue;
            for (const auto& [v, w] : newAdj[u])
                if (distance[src][u] + w < distance[src][v]) {
                    distance[src][v] = distance[src][u] + w;
                    pq.push({v, distance[src][v]});
                }
        }
        for (int v = 0; v < V; v++)
            if (distance[src][v] < INT_MAX)
                distance[src][v] += h[v] - h[src];
    }
    return true;
}
