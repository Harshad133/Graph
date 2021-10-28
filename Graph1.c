
// Representation of Graph By Adjsentecy Matrix

#include <stdio.h>
#include <malloc.h>

// Data Structure Of Graph
struct Graph
{
    int V;
    int E;
    int **adj;
};

// Create Graph this graph Diagram Show IN Figure

struct Graph *createGraph()
{
    int i, v, u;
    struct Graph *p;
    p = (struct Graph *)malloc(sizeof(struct Graph));
    printf("Enter Number Of Node = ");
    scanf("%d", &p->V);
    printf("Enter Number of Edges = ");
    fflush(stdin);
    scanf("%d", &p->E);

    p->adj = malloc(sizeof(int*)*p->V);
    for (i = 0; i < p->V; i++)
        p->adj[i] = (int*)malloc(sizeof(int) * p->V);

    for (i = 0; i < p->V; i++)
        for (int j = 0; j < p->V; j++)
            p->adj[i][j] = 0;

    for (i = 0; i < p->E; i++)
    {
        printf(" enter = ");
        scanf("%d %d", &v, &u);
        p->adj[v][u] = 1;
        p->adj[u][v] = 1;
    }
    return p;
}

int main()
{
    struct Graph *G;
    G = createGraph();

    // printing Graph

    printf("\n E = %d V = %d \n", G->E, G->V);
    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
            printf(" %d ", G->adj[i][j]);
        printf("\n");
    }

    return 0;
}
