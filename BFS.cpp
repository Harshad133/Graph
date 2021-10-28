#include<iostream>
using namespace std;

class Queue
{
private:
    struct Block
    {
        int front;
        int rear;
        int capacity;
        int *p;
    };
    Block *a;

public:
    Queue(int n)
    {
        a = new Block;
        a->capacity = n;
        a->front = -1;
        a->rear = -1;
        a->p = new int[n];
    }
    bool isEmpty()
    {
        return (a->front == -1);
    }
    void inQueue(int v)
    {
        a->rear = (a->rear + 1) % a->capacity;
        a->p[a->rear] = v;

        if (a->front == -1)
            a->front = a->rear;
    }
    int deQueue()
    {
        if (isEmpty())
            return -1;
        int v = a->p[a->front];
        if (a->front == a->rear)
        {
            a->front = -1;
            a->rear = -1;
        }
        else
            a->front = (a->front + 1) % a->capacity;
        return v;
    }
};

class Graph
{
private:
    int V;
    int E;
    int **adj;

public:
    Graph()
    {
        cout<<"\nEnter Number of Node = ";
        cin>>V;
        cout<<"\nEnter Numbwer of Edegs = ";
        cin>>E;

        adj = new int*[V];

        int i , j;
        for( i = 0 ; i< V ; i++)
            adj[i] = new int[V];

        for(i = 0 ; i< V ; i++)
            for(j = 0 ; j< V ; j++)
                adj[i][j] = 0;
        
        int v , u;
        for(i = 0 ; i< E ; i++){
                cout<<"\nEnter Edges = ";
                cin>>v>>u;
                adj[v][u] = 1;
                adj[u][v] = 1;
        }
    }
    void BFS()
    {
        Queue Q=V;
        int vis[V];
        int i , j;

        for(j = 0 ; j< V ; j++)
            vis[j] = 1;

        Q.inQueue(2);
        vis[2] = 2;

        while (!Q.isEmpty())
        {
            i = Q.deQueue();
            cout<<i<<" ";
            // vis[i] = 3;

            for(j = 0 ; j< V ; j++)
                if(adj[i][j] == 1 && vis[j] == 1){
                    Q.inQueue(j);
                    vis[j] = 2;
                }
        }
        
    }
};

int main()
{
    Graph G;
    G.BFS();
    return 0;
}