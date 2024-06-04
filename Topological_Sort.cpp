#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int visited[100];
int in[100];
int out[100];
vector<int> graph[100];
vector<int> topology_order;

void printG(int n)
{
    for (int i = 0; i < n; i++)
    {
        // if (graph[i].size() == 0)
        // continue;
        cout << "Node :" << i << " ";
        for (auto child : graph[i])
            cout << " -> " << child;

        cout << endl;
    }
}
//int timer = 0;
void Topological_Sort(int src)
{
    //in[src] = ++timer;
    visited[src] == 1;

    for (auto child : graph[src])
    {
        if (visited[child] == 0)
            Topological_Sort(child);
    }
    visited[src] = 2;
    //out[src] = ++timer;
    topology_order.insert(topology_order.begin(), 1, src);
}

int main()
{
    int n, e;
    cout<<"Enter Number of Nodes : ";
    cin >> n;
    cout<<"Enter Number of Edges : ";
    cin>> e;
    cout<<"Enter values : "<<endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    //printG(n + 1);
    for(int i=0;i<n;i++){
        if(visited[i]!=2){
            Topological_Sort(i);
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        cout << i << "->" << in[i] << "/" << out[i] << endl;
    }*/

    cout << "Topological order: ";
    for (auto i : topology_order)
        cout << i << " ";

    return 0;
}