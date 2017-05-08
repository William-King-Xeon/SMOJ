/*************************************************************************
	> File Name: 1831.cpp
	> Author: Xeon
	> Created Time: Tue 25 Apr 2017 15:12:00 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct EDGE
{
	int t,n;
} edge[120005];

int n,m,last[100005],cur=-1,
	Stop=0,Dindex=0,Bcnt=0,
	DFN[100005],LOW[100005],instack[100005],Stap[100005],Belong[100005],x[120005],y[120005],value[100005],size[10005],f[100005];

bool State[100005];

void AddEdge(int x,int y)
{
	cur++;
	edge[cur].t=y;
	edge[cur].n=last[x];
	last[x]=cur;
	return;
}

void Tarjan(int x)
{
	DFN[x]=LOW[x]=++Dindex;
	instack[x]=true;
	Stap[++Stop]=x;
	int tmp=last[x];
	while (tmp!=-1)
	{
		int target=edge[tmp].t;
		if (!DFN[target])
        {  
            Tarjan(target);  
            LOW[x]=min(LOW[x],LOW[target]);  
        }  
        else if (instack[target]&&LOW[x]>DFN[target]) LOW[x]=DFN[target];  
        tmp=edge[tmp].n;  
    }
    if (LOW[x]==DFN[x])
    {
		int v;
		Bcnt++;
		do
		{
			v=Stap[Stop--];  
			Belong[v]=Bcnt;
			if (value[v]>0) size[Bcnt]+=value[v];
			instack[v]=false;  
        } while(x!=v);
    }
    return;   
}

void ReBuild()
{
	cur=-1;
	memset(last,-1,sizeof(last));
	for (int i=1;i<=m;i++)
		if (Belong[x[i]]!=Belong[y[i]])
			AddEdge(Belong[x[i]],Belong[y[i]]);
	return;
}

void Solve()  
{  
    Dindex=Stop=Bcnt=0;  
    memset(LOW,0,sizeof(LOW));  
    memset(DFN,0,sizeof(DFN));  
    memset(instack,0,sizeof(instack));
    memset(Stap,0,sizeof(Stap));
    for (int i=1;i<=n;i++)
		if (!DFN[i]) Tarjan(i);
	ReBuild();
    return;  
}

void DFS(int r)
{
	State[r]=1;
	int tmp=last[r];
	f[r]=0;
	while (tmp!=-1)
	{
		int target=edge[tmp].t;
		if (!State[target]) DFS(target);
		f[r]+=max(f[target],f[target]+size[target]);
		tmp=edge[tmp].n;
	}
	return;
}

int main()
{
	freopen("1831.in","r",stdin);
	freopen("1831.out","w",stdout);

	int r;
	scanf("%d",&r);
	for (int R=1;R<=r;R++)
	{
		scanf("%d%d",&n,&m);

		for (int i=1;i<=n;i++) scanf("%d",&value[i]);

		cur=-1;
		memset(last,-1,sizeof(last));
		memset(edge,-1,sizeof(edge));

		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			x[i]++,y[i]++;
			AddEdge(x[i],y[i]);
		}

		Solve();

		for (int i=1;i<=Bcnt;i++) f[i]=-2000000000;

		int ans=-2000000000;
		memset(State,0,sizeof(State));
		for (int i=1;i<=Bcnt;i++)
		{
			if (!State[i]) DFS(i);
			ans=max(ans,f[i]+size[i]);
			ans=max(ans,f[i]);
		}

		printf("%d\n",ans);
	}

	return 0;
} 

