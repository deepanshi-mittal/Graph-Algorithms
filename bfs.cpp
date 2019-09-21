#include<bits/stdc++.h>

using namespace std;

void bfsu(int u,vector<int>adj[],int visit[])
{
    visit[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<" ";
        for(int x:adj[f])
        {
            if(visit[x]==0)
            {
                q.push(x);
                visit[x]=1;
            }
        }
    }
}

void bfs(vector<int> adj[],int v,int visit[])
{
    for(int i=0;i<v;i++)
    {
        if(visit[i]==0)
        {
            bfsu(i,adj,visit);
        }
    }
}

int main() {
	int v,e;
	cin>>v>>e;
	vector<int>adj[v];
	for(int i=0;i<e;i++)
	{
	    int s,d;
	    cin>>s>>d;
	    adj[s].push_back(d);
	    adj[d].push_back(s);
	}
	for(int i=0;i<v;i++)
	{
	    cout<<i;
	    for(int x : adj[i])
	    {
	        cout<<" -> "<<x;
	    }
	    cout<<endl;
	}
	int visit[v]={0};
	bfs(adj,v,visit);
	return 0;
}
