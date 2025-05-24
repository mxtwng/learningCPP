#pragma once
#include <vector>

void dfs(int node, std::vector<std::vector<int>>& adjList, std::vector<int>& visited);
void bfs(int start, std::vector<std::vector<int>>& adjList);