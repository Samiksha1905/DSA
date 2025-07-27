#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front=0,rear=0;
void BFS(int start,int n){
    int i;
    for(int i=0;i<n;i++){
        visited[i]=0;
        visited[start]=1;
        queue[++rear]=start;
        printf("BFS Traversal: ");
    }
    while(front<=rear){
        int node=queue[front++];
        printf("%d",node);

        for(int i=0;i<n;i++){
            if(adj[node][i] && !visited[i]){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
void DFS(int node,int n){
    int i;
    visited[node]=1;
    printf("%d",node);
    for(int i=0;i<n;i++){
        if(adj[node][i] && !visited[i]){
            DFS(i,n);
        }
    }
}
int main(){
    int n,e,i;
    int u,v,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        printf("Enter edge(u,v): ");
        scanf("%d %d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    BFS(start,n);

    for(int i=0;i<n;i++){
        visited[i]=0;
        printf("DFS Traversal: ");
        DFS(start,n);
        return 0;
    }
}