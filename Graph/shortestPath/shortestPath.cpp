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

//O(W + V + E), for graphs with non-negative integer weights from 0 to W, usually small W
int dials(int start, std::vector<std::vector<std::pair<int, int>>>& adjList, int maxW) {
    std::vector<int> dist (adjList.size(), INT_MAX);
    std::vector<std::queue<int>> buckets(maxW * adjList.size() + 1); //max possible distance
    dist[start] = 0;
    buckets[0].push(start);
    int idx = 0;

    while (true) {
        while (idx < buckets.size() && buckets[idx].empty()) idx++;
        if (idx == buckets.size()) break;

        int u = buckets[idx].front(); buckets[idx].pop();
        if (dist[u] < idx) continue;

        for (const auto& [v, w] : adjList[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                buckets[dist[v]].push(v);
            }
    }
    return 0;
}

//O(V + E) for edge with graph edge 0 or 1 only
int zeroOneBfs(int start, const std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<int> dist (adjList.size());
    std::deque<int> dq;
    dq.push_front(start);
    dist[start] = 0;

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (const auto& [v, w] : adjList[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
    }
    return 0;
}

//all can be used with unweighted, just make the weight = 1 lol