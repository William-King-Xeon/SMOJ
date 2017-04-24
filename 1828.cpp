/*************************************************************************
	> File Name: 1828.cpp
	> Author: Xeon
	> Created Time: Mon 24 Apr 2017 03:22:25 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define INFINITE 1000000000

struct EDGE
{
	int t,n,l;
} edge[605];

int x,y,z,last[305],cur=-1,
	f[305][305][2],g[305][305][2];

void Init()
{
	memset(last,-1,sizeof(last));
	for (int i=0;i<=x;i++)
		for (int j=0;j<=z;j++)
			g[i][j][0]=g[i][j][1]=
			f[i][j][0]=f[i][j][1]=INFINITE;
	return;
}

void AddEdge(int x,int y,int len)
{
	cur++;
	edge[cur].t=y;
	edge[cur].l=len;
	edge[cur].n=last[x];
	last[x]=cur;
	return;
}

void DFS(int cur,int father)
{
	f[cur][0][0]=f[cur][1][1]=0;
	int tmp=last[cur];
	while (tmp!=-1)
	{
		int target=edge[tmp].t,
			len=edge[tmp].l;
		if (target==father)
		{
			tmp=edge[tmp].n;
			continue;
		}
		DFS(target,cur);
		for (int i=0;i<=z;i++)
			for (int j=0;j<=i;j++)
			{
				int w=0;
				if (y==2) w=len;
						 g[cur][i][0]=min(g[cur][i][0],f[cur][j][0]+min(f[target][i-j][0]+w  ,f[target][i-j][1]));
				if (j>0) g[cur][i][1]=min(g[cur][i][1],f[cur][j][1]+min(f[target][i-j][1]+len,f[target][i-j][0]));
			}
		for (int i=0;i<=z;i++)
		{
			f[cur][i][0]=g[cur][i][0];
			f[cur][i][1]=g[cur][i][1];
			g[cur][i][0]=g[cur][i][1]=INFINITE;
		}
		tmp=edge[tmp].n;
	}
	return;
}

int main()
{
	freopen("1828.in","r",stdin);
	freopen("1828.out","w",stdout);

	scanf("%d%d%d",&x,&y,&z);
	Init();

	for (int i=1,a,b,len;i<x;i++)
	{
		scanf("%d%d%d",&a,&b,&len);
		AddEdge(a,b,len);
		AddEdge(b,a,len);
	}

	if (y+z-1>x)
	{
		printf("-1\n");
		return 0;
	}

	DFS(1,0);
	printf("%d\n",f[1][z][1]);
	return 0;
}
