#include<bits/stdc++.h>
using namespace std;

void acp(int u,vector<int> adj[],bool visited[],int parent[],bool ap[],int disc[],int low[])
{
    int static time=0;
    int c=0;
    visited[u]=true;
    disc[u]=low[u]=++time;
    for(auto i=adj[u].begin();i!=adj[u].end();i++)
    {
        int v=*i;
        if(!visited[v])
        {
            parent[v]=u;
            c++;
            acp(v,adj,visited,parent,ap,disc,low);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && c>1)
                ap[u]=true;
            if(parent[u]!=-1 && low[v]>=disc[u])
                ap[u]=true;
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],low[v]);
        }
    }
}

int main()
{
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<int> g[v];
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    bool visited[v];
    int parent[v];
    bool ap[v];
    int disc[v];
    int low[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        parent[i]=-1;
        ap[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(!(visited[i]))
        {
            acp(i,g,visited,parent,ap,disc,low);
        }
    }
    for(int i=0;i<v;i++)
    {
        if(ap[i]==true)
            cout<<i<<" ";
    }
}
