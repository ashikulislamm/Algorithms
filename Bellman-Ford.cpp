
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100];
int visited[100];
pair<int, int> cost[100];
vector<pair<int, int>> edges;

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

void relax(int u, int v, int w)
{
    if (cost[u].first + w < cost[v].first)
    {
        cost[v].first = cost[u].first + w;
        cost[v].second = u;
    }
}

bool has = false;

void bellman_ford(int src, int n)
{
    initialize(n, src);
    for (int i = 0; i < n - 1; i++)
    {
        for (auto i : edges)
        {
            int w;
            for (auto j : graph[i.first])
            {
                if (j.first == i.second)
                {
                    w = j.second;
                    break;
                }
            }
            relax(i.first, i.second, w);
        }
    }

    for (auto i : edges)
    {
        int w;
        for (auto j : graph[i.first])
        {
            if (j.first == i.second)
            {
                w = j.second;
                break;
            }
        }
        if (cost[i.first].first + w < cost[i.second].first)
        {
            has = true;
            break;
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
        edges.push_back({u, v});
    }

    printG(n);
    int s;
    cout << "Enter Source :";
    cin >> s;
    bellman_ford(s, n);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << cost[i].first << " " << cost[i].second << endl;
    }

    if (has)
        cout << "The graph contains negative cycle" << endl;
    else
        cout << "The graph dosen't contain negative cycle" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        printPath(0, i);
        cout << endl;
    }

    return 0;
}