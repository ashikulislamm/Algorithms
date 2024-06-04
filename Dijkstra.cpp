#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100];
int visited[100];
pair<int, int> cost[100];

void printG(int n)
{
    for (int i = 0; i < n; i++)
    {
        // if (graph[i].size() == 0)
        // continue;
        cout << "Node :" << i << " ";
        for (auto child : graph[i])
            cout << " -> " << child.first << " " << child.second;

        cout << endl;
    }
}

void initialize(int n, int src)
{
    for (int i = 0; i < n; i++)
    {
        if (i == src)
        {
            pair<int, int> tp;
            tp = {0, (int)NULL};
            cost[i] = tp;
        }
        else
        {
            pair<int, int> tp;
            tp = {9999, (int)NULL};
            cost[i] = tp;
        }
    }
}

int minval(int n)
{
    int mn = 9999, indx = -1;
    for (int i = 0; i < n; i++)
    {
        if (cost[i].first < mn && visited[i] == 0)
        {
            mn = cost[i].first;
            indx = i;
        }
    }

    return indx;
}

void relax(int u, int v, int w)
{
    if (cost[u].first + w < cost[v].first)
    {
        cost[v].first = cost[u].first + w;
        cost[v].second = u;
    }
}

void dijkstra(int src, int n)
{
    initialize(n, src);

    for (int i = 0; i < n; i++)
    {
        int mn = minval(n);
        visited[mn] = 1;
        for (auto j : graph[mn])
        {
            relax(mn, j.first, j.second);
        }
    }
}

void printPath(int s, int n)
{
    if (cost[n].second == (int)NULL)
    {
        cout << n << " ";
        return;
    }
    printPath(s, cost[n].second);
    cout << n << " ";
}

int main()
{
    int n, e;
    cout << "Enter Number of Nodes : ";
    cin >> n;
    cout << "Enter Number of Edges : ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    printG(n);
    int s;
    cout << "Enter Source :";
    cin >> s;
    dijkstra(s, n);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << cost[i].first << " " << cost[i].second << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        printPath(0, i);
        cout << endl;
    }

    return 0;
}