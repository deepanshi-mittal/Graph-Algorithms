#include<bits/stdc++.h>

using namespace std;

bool isSafe(int ri, int ci, int r,int c)
{
    return ((ri>=0)&& ri<r && ci>=0 &&ci<c);
}

void dfs(vector<vector<int> >&m,vector<vector<bool> >&visited,int a,int b)
{
    int r=m.size();
    int c=m[0].size();
    int ro[]={-1,-1,-1,0,0,1,1,1};
    int co[]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++)
    {
        int ri=a+ro[i];
        int ci=b+co[i];
        if(isSafe(ri,ci,r,c)&&m[ri][ci]==1 && visited[ri][ci]==0)
        {
            visited[ri][ci]=1;
            dfs(m,visited,ri,ci);
        }
    }
}

int fi(vector<vector<int> >&m,vector<vector<bool> >&visited)
{
    int r=m.size();
    int c=m[0].size();
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(m[i][j]==1 && visited[i][j]==0)
            {
                count++;
                dfs(m,visited,i,j);
                visited[i][j]=1;
            }
        }
    }
    return count;
}

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int> >m ;
    for(int i=0;i<r;i++)
    {
        vector<int> temp;
        for(int j=0;j<c;j++)
        {
            int a;
            cin>>a;
            temp.push_back(a);
        }
        m.push_back(temp);
    }
    vector<vector<bool> >visited;
    for(int i=0;i<r;i++)
    {
        vector<bool> temp;
        for(int j=0;j<c;j++)
        {
            temp.push_back(0);
        }
        visited.push_back(temp);
    }
    cout<<"Number of islands are "<<fi(m,visited);
    return 0;
}