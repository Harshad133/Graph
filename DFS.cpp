#include <iostream>
using namespace std;

class Stack
{
private:
    struct Block
    {
        int top;
        int capacity;
        int *h;
    };
    Block *st;

public:
    Stack(int cap)
    {
        st = new Block;
        st->capacity = cap;
        st->top = -1;
        st->h = new int[cap];
    }
    ~Stack()
    {
        delete st->h;
        delete st;
    }
    void push(int v)
    {
        if (st->top == st->capacity - 1)
            return;
        st->top++;
        st->h[st->top] = v;
    }
    int pop()
    {
        if (st->top == -1)
            return -1;
        int v = st->h[st->top];
        st->top--;
        return v;
    }
    bool isEmpty()
    {
        if (st->top == -1)
            return true;
        return false;
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
        cout << "\nEnter Number of Node = ";
        cin >> V;
        cout << "\nEnter Numbwer of Edegs = ";
        cin >> E;

        adj = new int *[V];

        int i, j;
        for (i = 0; i < V; i++)
            adj[i] = new int[V];

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                adj[i][j] = 0;

        int v, u;
        for (i = 0; i < E; i++)
        {
            cout << "\nEnter Edges = ";
            cin >> v >> u;
            adj[v][u] = 1;
            adj[u][v] = 1;
        }
    }
    void DFS()
    {
        int i, j;
        int vis[V];
        Stack s(V);

        for (i = 0; i < E; i++)
            vis[i] = 1; // all the node in ready status mens not input in Stack

        s.push(2);
        vis[2] = 2;

        while (!s.isEmpty())
        {
            i = s.pop();
            cout << i << " ";
            vis[i] = 3;

            for (j = 0; j < E; j++)
                if (adj[i][j] == 1 && vis[j] == 1)
                {
                    s.push(j);
                    vis[j] = 2;
                }
        }
    }
};

int main()
{
    Graph G;
    G.DFS();
    return 0;
}