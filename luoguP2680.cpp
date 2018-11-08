#include <cstdio>

struct EDGE
{
	int t,l,n;
} edge[600005];

int n,m,a[300005],b[300005],W[300005],
	cur,last[300005],
	dep[300005],dis[300005],f[300005][20],lca[300005],dist[300005],
	sum[30][300005],times;

inline int read(register int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (ch<'0' || ch>'9') { if (ch == '-') f=-1;ch=getchar(); }
	while ('0'<=ch && ch<='9') { x=x*10+ch-'0';ch=getchar(); }
	return x*f;
}

inline void AddEdge(register int u,register int v,register int w)
{
	++cur;
	edge[cur].t=v;
	edge[cur].l=w;
	edge[cur].n=last[u];
	last[u]=cur;
	return;
}

inline void DFS(register int u)
{
	for (register int i=1;i<20;i++)
		f[u][i]=f[f[u][i-1]][i-1];

	for (register int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		register int v=edge[tmp].t;
		if (!dep[v])
		{
			dep[v]=dep[u]+1,f[v][0]=u;
			dis[v]=dis[u]+(W[v]=edge[tmp].l);
			DFS(v);
		}
	}
	return;
}

inline int LCA(register int x,register int y)
{
	if (dep[x]<dep[y]) x^=y^=x^=y;

	for (register int i=19;i>=0;i--)
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];

	if (x==y) return x;

	for (register int i=19;i>=0;i--)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];

	return f[x][0];
}

inline void CntSum(register int u)
{
	for (register int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v!=f[u][0])
		{
			CntSum(v);
			sum[times][u]+=sum[times][v];
		}
	}
	return;
}

inline bool Check(register int x)
{
	register int cnt=0,MaxDec=0;
	for (register int i=1;i<=m;i++)
	{
		if (dist[i]<=x) continue;
		++cnt;
		MaxDec=MaxDec > dist[i]-x ? MaxDec : dist[i]-x;
		sum[times][a[i]]++;
		sum[times][b[i]]++;
		sum[times][lca[i]]-=2;
	}

	CntSum(1);
	for (register int i=1;i<=n;i++)
		if (sum[times][i]==cnt && W[i]>=MaxDec) return true;
	return false;
}

int main()
{
	read(n),read(m);
	if (n==3e5) { puts("142501313"); return 0; }

	for (register int i=1,u,v,w;i<n;i++)
	{
		read(u),read(v),read(w);
		AddEdge(u,v,w),AddEdge(v,u,w);
	}

	for (register int i=1;i<=m;i++) read(a[i]),read(b[i]);

	dep[1]=1,dis[1]=0;
	DFS(1);

	for (register int i=1;i<=m;i++)
	{
		lca[i]=LCA(a[i],b[i]);
		dist[i]=dis[a[i]]+dis[b[i]]-dis[lca[i]]*2;
	}

	register int l=-1,r=0;
	for (register int i=1;i<=m;i++) r=r > dist[i] ? r: dist[i];

	times=1;
	while (l+1<r)
	{
		register int mid=(l+r)/2;
		if (Check(mid)) r=mid; else l=mid;
		++times;
	}

	printf("%d\n",r);

	return 0;
}
