#pragma once
#include <vector>

class DSU {
    std::vector<int> parent, rank;

public:
    DSU(int n);
    int find(int x);
    bool unite(int a, int b);
};

void kruskal();
void prim();