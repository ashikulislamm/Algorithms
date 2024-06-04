#include <bits/stdc++.h>
using namespace std;

int Distance[100][100];
int Parent[100][100];

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                Distance[i][j] = 0;
            else
                Distance[i][j] = 9999;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            Parent[i][j] = (int)NULL;
        }
    }
}

void floys_warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Distance[i][j] > Distance[i][k] + Distance[k][j])
                {
                    Distance[i][j] = Distance[i][k] + Distance[k][j];
                    Parent[i][j] = Parent[k][j];
                }
            }
        }
    }
}

void path(int u, int v)
{
    if (u == v)
    {
        cout << u << " ";
    }
    else if (Parent[u][v] == (int)NULL)
    {
        cout << "No path from " << u << " to " << v << endl;
    }
    else
    {
        path(u, Parent[u][v]);
        cout << v << " ";
    }
}

int main()
{
    int n, e;
    cout<<"Enter Number of Nodes : ";
    cin >> n;
    cout<<"Enter Number of Edes : ";
    cin >> e;
    n++; // if starting node is not 0 but 1. else comment out

    initialize(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        Distance[u][v] = w;
        Parent[u][v] = u;
    }

    floys_warshall(n);

    cout << "\nStarting intdex is 0 :" << endl;

    cout<<"\nCost :"<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << Distance[i][j] << "\t";
        cout << endl;
    }

    cout << endl;

    cout<<"\nPredecessor :"<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << Parent[i][j] << "\t";
        cout << endl;
    }

    return 0;
}