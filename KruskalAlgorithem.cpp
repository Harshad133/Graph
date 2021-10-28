#include <iostream>
using namespace std;

struct Edge
{
    int wat;
    int v1;
    int v2;
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
        int m[6][6] = {0, 3, 0, 0, 1, 4, 3, 0, 6, 0, 0, 2, 0, 6, 0, 1, 0, 2, 0, 0, 1, 0, 5, 3, 1, 0, 0, 5, 0, 0, 4, 2, 2, 3, 0, 0};
        int i, j;

        V = 6;
        E = 9;

        adj = new int *[V];
        for (i = 0; i < V; i++)
            adj[i] = new int[V];

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                adj[i][j] = m[i][j];
    }
    int **makeSet()
    {
        int i, j;
        int **h = nullptr;

        try
        {
            h = new int *[V];
            if (h == nullptr)
                throw h;
        }
        catch (int **h)
        {
            cout << "Null Ponter Exeption in makeset Function line no = 35";
        }

        for (i = 0; i < V; i++)
            h[i] = new int[V];

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                h[i][j] = -1;

        for (i = 0; i < V; i++)
            h[i][0] = i;

        return h;
    }
    void sort(Edge *e)
    {
        int i, round;
        Edge temp;

        for (round = 1; round <= E - 1; round++)
            for (i = 0; i <= E - 1 - round; i++)
                if (e[i].wat > e[i + 1].wat)
                {
                    temp = e[i];
                    e[i] = e[i + 1];
                    e[i + 1] = temp;
                }
    }
    int findSet(int **p, int val)
    {
        int i, j;
        
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (p[i] == nullptr)
                    break;
                if (p[i][j] == val)
                    return i;
            }
        }
    }
    void uinonSet(int v, int u, int **p)
    {
        int i, count = 0;

        for (i = 0; i < V; i++)
        {
            if (p[v][i] == -1)
                break;
            count++;
        }

        for (i = 0; i < V; i++)
        {
            if (p[u][i] == -1)
                break;
            p[v][count] = p[u][i];
            count++;
        }
        delete[] p[u];
        p[u] = nullptr;
    }

    Edge *KruskalAlgo()
    {
        int i, j, k = 0;
        int t;
        int x, y;
        Edge *e, *A;
        e = new Edge[E];
        A = new Edge[E];

        for (i = 0; i < V; i++)
        {
            for (j = i + 1; j < V; j++)
            {
                if (adj[i][j] != 0)
                {
                    e[k].wat = adj[i][j];
                    e[k].v1 = i;
                    e[k].v2 = j;
                    k++;
                }
            }
        }

        int **p = makeSet();
        
        sort(e);

        k = 0;
        for (i = 0; i < E; i++)
        {
            x = findSet(p, e[i].v1);
            y = findSet(p, e[i].v2);

            if (x != y)
            {
                uinonSet(x, y, p);
                A[k] = e[i];
                k++;
            }
        }
        return A;
    }
};

int main()
{
    int i, j;
    Graph G;
    Edge *a;

    a = G.KruskalAlgo();

    int ma[6][6];

    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++)
            ma[i][j] = 0;

    for (i = 0; i < 5; i++)
    {
        ma[a[i].v1][a[i].v2] = a[i].wat;
        ma[a[i].v2][a[i].v1] = a[i].wat;
    }

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
            cout << "  " << ma[i][j];
        cout << endl;
    }

    return 0;
}