// Representation of Graph Using Adjesntecy List
#include <stdio.h>
#include <malloc.h>

struct ListNode
{
    int ver;
    struct ListNode *next;
};

struct Graph
{
    int V;
    int E;
    struct ListNode *adj;
};

struct Graph *createGraph()
{
    struct Graph *p;
    p = (struct Graph *)malloc(sizeof(struct Graph));
    printf("Enter Number Of Vertics = ");
    scanf("%d", &p->V);
    printf("Enter Number Of Edges = ");
    scanf("%d", &p->E);

    p->adj = (struct ListNode *)malloc(sizeof(struct ListNode) * p->V);

    int i;
    for (i = 0; i < p->V; i++)
    {
        p->adj[i].ver = i;
        p->adj[i].next = p->adj+i;
    }
    struct ListNode *temp;
    int v , u;
    for ( i = 0; i < p->E; i++)
    {
        printf("Enter Edges = ");
        scanf("%d %d",&v,&u);

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->ver = u;
        temp->next = p->adj+v;
        struct ListNode *t = p->adj+v;
        while(t->next != p->adj+v)
            t=t->next;
        t->next = temp;
    }
    return p; 
}

int main()
{
    struct Graph *G;
    G = createGraph();
    struct ListNode *t;
    printf(" E = %d V = %d",G->E,G->V);

    for (int i = 0; i < G->V; i++)
    {
        printf("\n");
        printf("%d " , G->adj[i].ver);
        t = G->adj[i].next;
        while( t != G->adj+i){
            printf("%d " , t->ver);
            t=t->next;
        }
        
    }
    
    return 0;
}