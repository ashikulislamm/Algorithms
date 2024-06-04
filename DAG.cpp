#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>p;
int mx=999;
int visited[100];
vector<p>g[100];
pair<int,int>cost[100];
vector<int>topology_order;
void Topological_Sort(int src)
{
    //in[src] = ++timer;
    visited[src] = 1;

    for (auto child : g[src])
    {
        if (visited[child.first] == 0)
            Topological_Sort(child.first);
    }
    visited[src] = 2;
    //out[src] = ++timer;
    topology_order.insert(topology_order.begin(), 1, src);
}
void RELAX(int u, int v, int w)
{
    if (cost[v].second > cost[u].second + w)
    {
        cost[v].second = cost[u].second + w;
        cost[v].first = u;
    }
}

void DAG(int node, int n)
{

    for(int i=1; i<=n; i++)
    {
        if(visited[i]!=2)
        {
            Topological_Sort(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == node)
        {
            cost[i].first = (int)NULL;
            cost[i].second = 0;
        }
        else
        {
            cost[i].first = (int)NULL;
            cost[i].second = mx;
        }
    }

    for (int j=1;j<=n;j++)
    {
        for (auto v : g[j])
            RELAX(j, v.first, v.second);
    }
}

void PATH(int v){

    if(cost[v].first==0){
        cout<<v<<" ";
        return;
    }
    PATH(cost[v].first);
    cout<<v<<" ";

}
int main()
{
    int n,e;
    cout<<"Enter Number of Nodes : ";
    cin>>n;
    cout<<"Enter Number of Edges : ";
    cin>>e;
    cout<<"Enter The values : ";
    while(e--)
    {
        int n1,n2,w;
        cin>>n1>>n2>>w;

        g[n1].push_back(make_pair(n2,w));

    }
    int s;
    cout<<"Enter Source Node : ";
    cin>>s;
    DAG(s,n);
    cout<<"Path Values : "<<endl;
    /*for (int i = 1; i <= n; i++)
    {
        cout << "Node : " << i << " "
             << "Previous node: " << cost[i].first << " "
             << "Cost :" << cost[i].second << endl;
    }*/

    /*for (int i = 1; i <= n; i++)
    {

        cout << "Path " << i << " " <<"Cost : " << cost[i].second << endl;
    }*/
    for (int i = 1; i <= n; i++)
    {

        cout << "Path : "<<endl;
        PATH(i);
        cout<<"cost: "<<cost[i].second<<endl;
    }

}