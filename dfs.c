#include<stdio.h>
#include<stdbool.h>

#define max 20

int graph[max][max], size; 
bool visited[max];

void dfs(int node) {
    visited[node]=true;
    printf("\nVisited node : %d", node);
    
    for(int i=0;i<size;i++) {
        if(graph[node][i]==1 && !visited[i])
            dfs(i);
    }
    
}

int main() {
    printf("Enter number of nodes : ");
    scanf("%d", &size);
    
    printf("Enter adjacency mat : ");
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int startNode;
    printf("\nEnter node from which to start : ");
    scanf("%d", &startNode);
    
    for(int i=0;i<size;i++)
        visited[i]=false;
    
    dfs(startNode);
    
    return 0;
}
