#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src;
    int dest;
    int weight;
};

int find(int parent[], int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return find(parent, parent[x]);
}

void unionSets(int parent[], int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    parent[rootB] = rootA;
}

int compareEdges(const void *a, const void *b)
{
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;

    return edgeA->weight - edgeB->weight;
}

int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Edge edges[E];
    printf("\nEnter each edge as: source destination weight\n");
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);

        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int edgeCount = 0;
    int totalWeight = 0;

    printf("\nEdges selected for MST:\n");
    for (int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        if (rootU != rootV)
        {
            printf("%d -- %d   Weight = %d\n",
                   u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSets(parent, u, v);
            edgeCount++;
        }
    }

    printf("\nTotal weight of MST = %d\n", totalWeight);

    return 0;
}