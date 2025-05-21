#include "shortestPath.h"
#include <queue>
#include <vector>
#include <climits>

int dijkstra(int start, std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<int> distance(adjList.size(), INT_MAX);
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > pq;

    distance[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int node = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue; //this is basically the visited vector, the other one isnt really needed

        for (const auto& [neighbor, weight] : adjList[node])
            if (distance[node] + weight < distance[neighbor]) {
                //main logic operations
                pq.push({neighbor, distance[node] + weight});
                distance[neighbor] = distance[node] + weight;
            }
    }
}

int bellmanFord(int start, std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<int> distance(adjList.size(), INT_MAX);
    distance[start] = 0;

    std::vector<std::tuple<int, int, int>> edges;
    for (int u = 0; u < adjList.size(); u++)
        for (auto [v, w] : adjList[u])
            edges.push_back({u, v, w});

    for (int i = 1; i < adjList.size(); i++)
        for (const auto& [u, v, w] : edges)
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
    
    //neg cycle detection
    for (int i = 1; i < adjList.size(); i++)
        for (const auto& [u, v, w] : edges)
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
                return -1;

    return 0;
}