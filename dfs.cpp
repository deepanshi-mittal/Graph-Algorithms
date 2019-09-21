#include<bits/stdc++.h>

using namespace std;

void dfsu(int u,vector<int>adj[],int visit[])
{                      
    visit[u]=1;                //updating the visit array 
    cout<<u<<" ";              //printing the node 
    for(int x:adj[u])
    {
        if(visit[x]==0)
        {
            dfsu(x,adj,visit);
        }
    }
}

void dfs(vector<int> adj[],int v,int visit[])
{
    for(int i=0;i<v;i++)
    {
        if(visit[i]==0)
        {
            dfsu(i,adj,visit);
        }
    }
}

int main() {
	int v,e;    //v is for number of vertices and e for number of edges
	cin>>v>>e;
	vector<int>adj[v];    //adjacency list
	for(int i=0;i<e;i++)
	{
	    int s,d;
	    cin>>s>>d;        //input edges using source(s) and destination (d)
	    adj[s].push_back(d);
	    adj[d].push_back(s);
	}
	for(int i=0;i<v;i++)   //this loop will print the adjacency list
	{
	    cout<<i;
	    for(int x : adj[i])
	    {
	        cout<<" -> "<<x;
	    }
	    cout<<endl;
	}
	int visit[v]={0};      //array to check whether the node is traversed or not
	dfs(adj,v,visit);      
	return 0;
}
