#include <cstdio>

struct EDGE
{
    int t,n;
} edge[1000005];

int cur,last[500005],
    n,m,s,dep[500005],f[500005][20];

void AddEdge(int u,int v)
{
    ++cur;
    edge[cur].t=v;
    edge[cur].n=last[u];
    last[u]=cur;
    return;
}

void DFS(int u)
{
    for (int i=1;i<20;i++)
        f[u][i]=f[f[u][i-1]][i-1];

    for (int tmp=last[u];tmp;tmp=edge[tmp].n)
    {
        int v=edge[tmp].t;
        if (v!=f[u][0])
        {
            f[v][0]=u,dep[v]=dep[u]+1;
            DFS(v);
        }
    }

    return;
}

int LCA(int x,int y)
{
    if (dep[x]<dep[y]) {int t=x; x=y; y=t;}

    for (int i=19;i>=0;i--)
        if (dep[f[x][i]]>=dep[y]) x=f[x][i];

    if (x==y) return x;

    for (int i=19;i>=0;i--)
        if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];

    return f[x][0];
}

int main()
{
    scanf("%d%d%d",&n,&m,&s);

    for (int i=1,u,v;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        AddEdge(u,v),AddEdge(v,u);
    }

    dep[s]=1;
    DFS(s);

    for (int i=1,a,b;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA(a,b));
    }

    return 0;
}
