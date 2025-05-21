#pragma once


int dijkstra(int start, std::vector<std::vector<std::pair<int, int>>>& adjList);
int bellmanFord(int start, std::vector<std::vector<std::pair<int, int>>>& adjList);

void floydWarshall(int V, std::vector<std::vector<std::pair<int, int>>>& adjList);
bool johnson(int V, std::vector<std::vector<std::pair<int, int>>>& adjList);

