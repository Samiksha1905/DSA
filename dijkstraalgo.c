#include <stdio.h> 
#include <limits.h> 
#define V 5 
 
int minDist(int dist[], int spt[]) { 
    int min = INT_MAX, index; 
    for (int v = 0; v < V; v++) 
        if (!spt[v] && dist[v] <= min) 
            min = dist[v], index = v; 
    return index; 
} 
 
void dijkstra(int graph[V][V], int src) { 
    int dist[V], spt[V]; 
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, spt[i] = 
0; 
    dist[src] = 0; 
 
    for (int i = 0; i < V - 1; i++) { 
        int u = minDist(dist, spt); 
        spt[u] = 1; 
        for (int v = 0; v < V; v++) 
            if (!spt[v] && graph[u][v] && dist[u] + 
graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
 
    printf("\nDijkstra's Shortest Paths:\nVertex\tDistance\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d\t%d\n", i, dist[i]); 
} 
int main() { 
int graph[V][V] = { 
{0, 10, 0, 0, 5}, 
{0, 0, 1, 0, 2}, 
{0, 0, 0, 4, 0}, 
{7, 0, 6, 0, 0}, 
{0, 3, 9, 2, 0}, 
}; 
dijkstra(graph, 0); 
return 0;
}