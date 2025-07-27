#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

// Find operation with path compression
int find(int i) {
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i]);
}

// Union operation
void unionSet(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset != yset)
        parent[xset] = yset;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(Edge), compare);

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int totalCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    int count = 0;
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);
}

int main() {
    int n = 5; // Number of vertices
    int e = 7; // Number of edges

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 2, 25},
        {3, 4, 2}
    };

    kruskal(edges, n, e);
    return 0;
}