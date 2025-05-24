#include "traversal.h"

#include <vector>
#include <queue>

void dfs(int node, std::vector<std::vector<int>>& adjList, std::vector<int>& visited) {
    visited[node] = true;
    for (int neighbor: adjList[node])
        if (!visited[neighbor])
            //main logic operations here
            dfs(neighbor, adjList, visited);
}

void bfs(int start, std::vector<std::vector<int>>& adjList) {
    std::queue<int> q;
    std::vector<bool> visited(adjList.size(), false);
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor: adjList[node])
            if (!visited[neighbor]) {
                //main logic operations here
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}