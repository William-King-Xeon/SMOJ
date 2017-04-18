/*************************************************************************
	> File Name: 1797.cpp
	> Author: Xeon
	> Created Time: 2017年04月18日 星期二 09时37分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
/* Test STL(queue) !!! */
#include<queue>
#define INF 1000000000
using namespace std;

struct EDGE
{
	int t,n,co;
} edge[205];

void Init(void);
void AddEdge(int x,int y,int company);
int CntOne(int num);
void SPFA(void);

bool Connect[15][45][45];
int n,f,dis[45][1024],cost[45][15],cur,last[45];


int main()
{
	freopen("1797.in","r",stdin);
	freopen("1797.out","w",stdout);

	int r;
	scanf("%d",&r);
	for (int R=1;R<=r;R++)
	{
		scanf("%d%d",&n,&f);
		Init();
		for (int i=0,k;i<f;i++)
		{
			scanf("%d",&k);
			for (int j=0,a,b;j<k;j++)
			{
				scanf("%d%d",&a,&b);
				AddEdge(a,b,i);
				Connect[i][a][b]=true;
			}
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<f;j++)
				scanf("%d",&cost[i][j]);
		SPFA();
		for (int i=1;i<n;i++)
			if (dis[i][0]!=INF) printf("%d ",dis[i][0]); else printf("-1 ");
		printf("\n");
	}
	return 0;
}

void Init(void)
{
	cur=-1;
	for (int i=0;i<n;i++)
		for (int j=0;j<(1<<f);j++)
			dis[i][j]=INF;
	for (int i=0;i<f;i++)
		for (int a=0;a<n;a++)
			for (int b=0;b<n;b++)
				Connect[i][a][b]=false;
	for (int i=0;i<n;i++) last[i]=-1;
	for (int i=0;i<n*2;i++) edge[i].t=-1,edge[i].n=-1;
	return;
}

void AddEdge(int x,int y,int company)
{
	edge[++cur].t=y;
	edge[cur].n=last[x];
	edge[cur].co=company;
	last[x]=cur;
}

int CntOne(int num)
{
	int ans=0;
	while (num!=0)
	{
		if (num&1) ans++;
		num=(num>>1);
	}
	return ans;
}

void SPFA(void)
{
	queue< pair<int,int> > q;
	q.push(make_pair(0,0));
	dis[0][0]=0;
	while (!q.empty())
	{
		int cur=q.front().first,
			set=q.front().second;
		q.pop();
		/* Buy! */
		for (int i=0;i<f;i++)
			if (!(set&(1<<i)))
			{
				int new_set=set+(1<<i);
				if (CntOne(new_set)<=3&&dis[cur][set]+cost[cur][i]<dis[cur][new_set])
				{
					dis[cur][new_set]=dis[cur][set]+cost[cur][i];
					q.push(make_pair(cur,new_set));
				}
			}
		/* Go! */
		for (int tmp=last[cur];tmp!=-1;tmp=edge[tmp].n)
			if (set&(1<<edge[tmp].co))
			{
				int t=edge[tmp].t,
					c=edge[tmp].co,
					new_set=set-(1<<c);
				if (Connect[c][cur][t]&&dis[cur][set]<dis[t][new_set])
				{
					dis[t][new_set]=dis[cur][set];
					q.push(make_pair(t,new_set));
				}
			}
	}
}

