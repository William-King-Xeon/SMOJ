#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct EDGE
{
    int t,n;
} edge[100005];

int n,m,value[100005],u[100005],v[100005],
    cur,last[100005],
    Index,LOW[100005],DFN[100005],Top,Stack[100005],InStack[100005],
    Bcnt,Belong[100005],sum[100005],
    f[100005],vis[100005];

void AddEdge(int u,int v)
{
    cur++;
    edge[cur].t=v;
    edge[cur].n=last[u];
    last[u]=cur;
    return;
}

void Tarjan(int u)
{
	DFN[u]=LOW[u]=++Index;
	InStack[u]=true; Stack[++Top]=u;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (!DFN[v])
        {
            Tarjan(v);
            LOW[u]=min(LOW[u],LOW[v]);
        }
        else
        if (InStack[v]) LOW[u]=min(LOW[u],DFN[v]);
    }
    if (LOW[u]==DFN[u])
    {
		int v; Bcnt++;
		do
		{
			v=Stack[Top--];
			sum[Bcnt]+=value[v];
			Belong[v]=Bcnt;
			InStack[v]=false;
        } while (u!=v);
    }
    return;
}

void DFS(int u)
{
    if (vis[u]) return;
    f[u]=sum[u]; sum[u]=0; vis[u]=true;
    for (int tmp=last[u];tmp;tmp=edge[tmp].n)
    {
        int v=edge[tmp].t;
        if (!vis[v]) DFS(v);
        sum[u]=max(sum[u],f[v]);
    }
    f[u]+=sum[u];
    return;
}

int main()
{
    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        AddEdge(u[i],v[i]);
    }

    for (int i=1;i<=n;i++)
        if (!DFN[i]) Tarjan(i);

    cur=0;
    memset(last,0,sizeof(last));

    for (int i=1;i<=m;i++)
        if (Belong[u[i]]!=Belong[v[i]])
            AddEdge(Belong[u[i]],Belong[v[i]]);

    for (int i=1;i<=Bcnt;i++)
        if (!vis[i]) DFS(i);

    int ans=0;
    for (int i=1;i<=Bcnt;i++)
        ans=max(ans,f[i]);
    printf("%d\n",ans);

    return 0;
}
