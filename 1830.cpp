/*************************************************************************
	> File Name: 1830.cpp
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
} edge[60005];

int n,m,last[50005],cur=-1,
	Stop=0,Dindex=0,Bcnt=0,

	DFN[50005],LOW[50005],instack[50005],Stap[50005],Belong[50005],num[50005],x[60005],y[60005];

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
			instack[v]=false;  
        } while(x!=v);
    }
    return;   
}

void Cnt()
{
	for (int i=1;i<=m;i++)
		if (Belong[x[i]]!=Belong[y[i]])
			num[Belong[x[i]]]++;
	return;
}

void Solve()  
{  
    Dindex=Stop=Bcnt=0;  
    memset(LOW,0,sizeof(LOW));  
    memset(DFN,0,sizeof(DFN));  
    memset(instack,0,sizeof(instack));
    memset(Stap,0,sizeof(Stap));
	memset(num,0,sizeof(num));
    for (int i=1;i<=n;i++)
		if (!DFN[i]) Tarjan(i);
	Cnt();
    return;  
}

int main()
{
	freopen("1830.in","r",stdin);
	freopen("1830.out","w",stdout);

	int r;
	scanf("%d",&r);
	for (int R=1;R<=r;R++)
	{
		scanf("%d%d",&n,&m);

		cur=-1;
		memset(last,-1,sizeof(last));
		memset(edge,-1,sizeof(edge));

		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			AddEdge(x[i],y[i]);
		}

		Solve();

		int OK=true,ans=0;
		for (int i=1;i<=Bcnt;i++)
			if (!num[i])
			{
				if (ans)
				{
					OK=false;
					break;
				}
				ans=i;
			}

		if (OK) printf("Yes\n"); else printf("No\n");
	}

	return 0;
} 

