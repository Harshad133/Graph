#include<stdio.h>
#include<malloc.h>
#define INF 999999
#define NIL 9

typedef struct
{
    int V;
    int E;
    int **adj;
}Graph;

typedef struct
{
    int key;
    int parnte;
}Block;

Graph* createGraph()
{
    int ma[6][6] = {0,3,4,0,0,0,3,0,2,7,4,0,4,2,0,5,0,0,0,7,5,0,2,1,0,4,0,2,0,6,0,0,0,1,6,0};
    Graph *p;
    p = (Graph*)malloc(sizeof(Graph));

    p->V = 6;
    p->E = 9;

    p->adj = (int**)malloc(sizeof(int*) * p->V);

    for (int i = 0; i < p->V; i++)
    {
        p->adj[i] = (int*)malloc(sizeof(int) * p->V);
    }

    for (int i = 0; i < p->V; i++)
    {
        for (int j = 0; j < p->V; j++)
        {
            p->adj[i][j] = ma[i][j];
        }
        
    }
    
    return p;
}

int minOfKey(Block *p , int *count , Graph *G)
{
    int i , j;
    for(i=0;i<G->V;i++)
        if(count[i] != 1)
            break;

    int min = i;

    for ( j = i+1 ; j < G->V; j++)
    {
        if(p[j].key < p[min].key && count[j] == 0)
            min = j;
    }
    return min;
}

void prims(Graph *G , int mat[][6])
{
    // p is show Queue
    Block *p = (Block*)malloc(sizeof(Block) * G->V);

    // count show the visting status of vertics
    // this count help in find minumum keys 
    int count[6] = {0};

    int i,j;

    for ( i = 0; i < G->V; i++)
    {
        // key show the cost of vertics which minmumm cost connect graph
        p[i].key = INF;

        // parnte show the parnte node indax
        p[i].parnte = NIL;
    }
    
    //assign arbtriy node key = 0 , our arbtriy node is 0 
    p[0].key = 0;

    int k;
    for ( i = 0; i < G->V; i++)
    {
        // minOfKey() giev minumum key value indax

        k = minOfKey(p,count,G);
        count[k] = 1;

        if(p[k].key != 0)
        {
            mat[k][p[k].parnte] = p[k].key;
            mat[p[k].parnte][k] = p[k].key;
        }

        for ( j = 0; j < G->V; j++)
        {
            if(G->adj[k][j] != 0 && count[j] == 0 && G->adj[k][j] < p[j].key)
            {
                p[j].key = G->adj[k][j];
                p[j].parnte = k;
            }
        }
        
    }

}

void print(Graph *G)
{
    int i, j;

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
                printf("%6d", G->adj[i][j]);
        printf("\n");
    }
}

int main()
{
    Graph *G;
    G = createGraph();
    // print(G);

    int m[6][6] = {0};
    prims(G , m);

    for(int i = 0 ; i < G->V ; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            printf("%6d",m[i][j]);
        }
        printf("\n");
    }
    return 0 ;
}