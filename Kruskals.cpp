#include<bits/stdc++.h>
using namespace std;
int parent[100];
void make(int n)
{
    parent[n]=n;
}

int find(int n)
{
    if(parent[n]==n)
    {
        return n;
    }
    else{
        return parent[n]=find(parent[n]);
    }
}

void Union(int a , int b)
{
    a=parent[a];
    b=parent[b];
    if(a!=b)
    {
        parent[b]=a;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    n++;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++)
    {
        make(i);
    }
    int cost=0;
    cout<<"Edges included :"<<endl;
    for(auto i:edges)
    {
        int u=i.second.first;
        int v=i.second.second;
        int w=i.first;

        if(find(u)==find(v)){
            continue;

        }
        Union(u,v);
        cout<<u<<" "<<v<<endl;
        cost+=w;
    }
    cout<<"Min Cost : "<<endl;
    cout<<cost<<endl;

    return 0;
}