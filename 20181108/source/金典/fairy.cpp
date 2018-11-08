#pragma GCC optimize("O3")
#include <cstdio>

struct EDGE
{
	int t,n;
} edge[20005];

int n,m,u[10005],v[10005],ans,id[10005],vis[10005],color[10005],
	cur,last[10005],
	U,V;
bool OK;

void AddEdge(int u,int v)
{
	++cur;
	edge[cur].t=v;
	edge[cur].n=last[u];
	last[u]=cur;
	return;
}

void DFS(int u,int sign)
{
	if (!OK) return;
	vis[u]=sign;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		if (!OK) return;
		int v=edge[tmp].t;
		if (u==U && v==V || u==V && v==U) continue;
		if (vis[v]!=sign)
		{
			color[v]=1-color[u];
			DFS(v,sign);
		}
		if (color[v]==color[u])
		{
			OK=false;
			return;
		}
	}
	return;
}

int main()
{
	freopen("fairy.in","r",stdin);
	freopen("fairy.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		AddEdge(u[i],v[i]),
		AddEdge(v[i],u[i]);
	}
	
	for (int i=1;i<=m;i++)
	{
		OK=true;
		U=u[i],V=v[i];
		for (int j=1;j<=n && OK;j++)
			if (vis[j]!=i)
			{
				color[j]=0;
				DFS(j,i);
			}
		if (OK) id[++ans]=i;
	}
	
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		printf("%d ",id[i]);
	printf("\n");
	
	return 0;
}
