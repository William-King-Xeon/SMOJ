/*************************************************************************
	> File Name: 1832.cpp
	> Author: Xeon
	> Created Time: Thu 27 Apr 2017 09:31:20 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct EDGE
{
	int t,n;
} edge[200005];

int cur=-1,last[100005],n,m,DelFrom=-1,DelTo=-1,dis[100005],f[100005][5],State[100005];

void AddEdge(int x,int y)
{
	cur++;
	edge[cur].t=y;
	edge[cur].n=last[x];
	last[x]=cur;
	return;
}

void Find(int cur,int father)
{
	dis[cur]+=1;
	if (dis[cur]==2) return;
	int tmp=last[cur];
	while (tmp!=-1)
	{
	  	int target=edge[tmp].t;
	  	if (target==father)
		{
	  		tmp=edge[tmp].n;
	  		continue;
		}
	  	Find(target,cur);
	  	if (DelFrom!=-1) return;
	  	if (dis[target]==2)
		{
	  		DelFrom=cur;
	  		DelTo=target;
			return;
		}
	  	tmp=edge[tmp].n;
	}
	return;
}

void DFS(int cur,int father)
{
	State[cur]=true;
	int tmp=last[cur];
	f[cur][0]=0;f[cur][1]=1;
	while (tmp!=-1)
	{
		int target=edge[tmp].t;
		if (State[target]||
			target==DelFrom && cur==DelTo  ||
			target==DelTo   && cur==DelFrom)
		{
			tmp=edge[tmp].n;
			continue;
		}
		DFS(target,cur);
		f[cur][1]+=min(f[target][1],f[target][0]);
		f[cur][0]+=f[target][1];
		tmp=edge[tmp].n;
	}
	return;
}

void Init()
{
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	memset(State,0,sizeof(State));
	return;
}

int main()
{
	freopen("1832.in","r",stdin);
	freopen("1832.out","w",stdout);

	scanf("%d",&n);
	memset(last,-1,sizeof(last));
	for (int x=1;x<=n;x++)
	{
		scanf("%d",&m);
		for (int j=1,y;j<=m;j++)
		{
			scanf("%d",&y);
			AddEdge(x,y);
		}
	}

	Init();

	Find(1,-1);
	DFS(DelFrom,-1);

	int ans=f[DelFrom][1];
	Init();
	DFS(DelTo,-1);
	ans=min(ans,f[DelTo][1]);

	printf("%d",ans);
	return 0;
}
