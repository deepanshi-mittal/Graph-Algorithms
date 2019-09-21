#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }
    stack<int> t;
    int tp=s.top();
    t.push(tp);
    s.pop();
    while(!s.empty())
    {
        tp=s.top();
        s.pop();
        while(!t.empty()&&t.top()>tp)
        {
            int f=t.top();
            t.pop();
            s.push(f);
        }
        t.push(tp);
    }
    while(!t.empty())
    {
        cout<<t.top()<<" ";
        t.pop();
    }
}