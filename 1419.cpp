/*************************************************************************
	> File Name: 1491.cpp
	> Author: Xeon
	> Created Time: Tue 25 Apr 2017 09:51:30 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct EDGE
{
	int t,n;
} edge[50005];

int n,m,x[50005],y[50005],last[50005],cur=-1,
	Stop=0,Dindex=0,Bcnt=0,
	DFN[50005],LOW[50005],instack[50005],Stap[50005],Belong[50005],num[50005],size[50005];

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
    if(LOW[x]==DFN[x])
    {
		int v;
		Bcnt+=1;
		do
		{
			v=Stap[Stop--];
			size[Bcnt]++;
			Belong[v]=Bcnt;
			instack[v]=false;
        } while(x!=v);
    }
    return;
}
void Solve()
{
    Dindex=Stop=Bcnt=0;
    memset(LOW,0,sizeof(LOW));
    memset(DFN,0,sizeof(DFN));
    memset(size,0,sizeof(size));
    memset(instack,0,sizeof(instack));
    memset(Stap,0,sizeof(Stap));
    for (int i=1;i<=n;i++)
		if (!DFN[i]) Tarjan(i);
    return;
}
void Cnt()
{
    for (int i=1;i<=m;i++)
		if (Belong[x[i]]!=Belong[y[i]]) num[Belong[x[i]]]++;
    return;
}
int main()
{
	freopen("1419.in","r",stdin);
	freopen("1419.out","w",stdout);

	scanf("%d%d",&n,&m);
	memset(last,-1,sizeof(last));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		AddEdge(x[i],y[i]);
	}

	Solve();
	memset(num,0,sizeof(num));
	Cnt();

	int ans=0;
	for (int i=1;i<=Bcnt;i++)
		if (!num[i])
		{
			if (ans>0)
			{
				ans=0;
				break;
			}
			ans=size[i];
		}
	printf("%d",ans);

	return 0;
}
