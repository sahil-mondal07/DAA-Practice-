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

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Array of edges
    struct Edge edges[E];

    // Input edges
    printf("\nEnter each edge as: source destination weight\n");

    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);

        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    // Sort edges according to weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Parent array for DSU
    int parent[V];

    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int edgeCount = 0;
    int totalWeight = 0;

    printf("\nEdges selected for MST:\n");

    // Process edges from smallest weight to largest
    for (int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        // Find roots
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // If roots are different, no cycle is formed
        if (rootU != rootV)
        {
            printf("%d -- %d   Weight = %d\n",
                   u, v, edges[i].weight);

            // Add weight
            totalWeight += edges[i].weight;

            // Join the two sets
            unionSets(parent, u, v);

            // One more edge has been added to MST
            edgeCount++;
        }
    }

    printf("\nTotal weight of MST = %d\n", totalWeight);

    return 0;
}