#include <stdio.h>
#include <malloc.h>
#define INF 9999

typedef struct
{
    int V;
    int E;
    int **a;
} Graph;

Graph *create()
{
    Graph *p;
    p = (Graph *)malloc(sizeof(Graph));
    p->V = 4;
    p->E = 4;
    p->a = (int **)malloc(sizeof(int *) * p->V);

    for (int i = 0; i < p->V; i++)
    {
        p->a[i] = (int *)malloc(sizeof(int) * p->V);
    }

    return p;
}

void floydWarshall(Graph *G)
{
    int i, j, k;
    int dist[4][4];

    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
            dist[i][j] = G->a[i][j];

    for (k = 0; k < G->V; k++)
        for (i = 0; i < G->V; i++)
            for (j = 0; j < G->V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    //end of j
    //end of i
    //end of k

    //k show intermedeted node
    //i to j node shoreted path

    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
            G->a[i][j] = dist[i][j];
}

void print(Graph *G)
{
    int i, j;

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
            if (G->a[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", G->a[i][j]);
        printf("\n");
    }
}

int main()
{
    Graph *G;
    G = create();
    int m[][4] = {{0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            G->a[i][j] = m[i][j];
        }
    }
    print(G);
    floydWarshall(G);
    printf("\n Shoretd path :::::-------->>> \n\n");
    print(G);
    return 0;
}