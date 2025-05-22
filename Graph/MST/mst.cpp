#include "mst.h"
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <climits>

int kruskal(int n, std::vector<std::tuple<int, int, int>>& edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mstCost = 0;

    for (const auto& [u, v, w] : edges)
        if (dsu.unite(u, v))
            mstCost += w;

    return mstCost;
}

int prim(int start, std::vector<std::vector<std::pair<int, int>>>& adjList) {
    std::vector<bool> visited(adjList.size(), false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    int totalCost = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        const auto& [cost, node] = pq.top(); pq.pop();
        if (visited[node]) continue;

        visited[node] = true;
        totalCost += cost;

        for (const auto& [neighbor, weight] : adjList[node])
            if (!visited[neighbor])
                pq.push({neighbor, weight});
    }
    return totalCost;
}