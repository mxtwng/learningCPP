#include "mst.h"

DSU::DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int DSU::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool DSU::unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return false;

    if (rank[rootA] < rank[rootB])
        parent[rootA] = rootB;
    else if (rank[rootA] > rank[rootB])
        parent[rootB] = rootA;
    else
        parent[rootB] = rootA;
        rank[rootA]++;
    
    return true;
}