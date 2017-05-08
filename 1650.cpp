/*************************************************************************
	> File Name: 1650.cpp
	> Author: Xeon
	> Created Time: 2017年05月08日 星期一 13时38分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct EDGE
{
    int target,next;
} edge[20005];

int last[10005],cur=-1,
    n,m,
    low[10005],Degree[10005],
    cnt=0;
bool Visit[10005],map[10005][10005];

void AddEdge(int u,int v)
{
    cur++;
    edge[cur].target=v;
    edge[cur].next=last[u];
    last[u]=cur;
    return;
}

void DFS(int x,int father)
{
    Visit[x]=true;
    low[x]=++cnt;
    int tmp=last[x];
    while (tmp!=-1)
    {
        int target=edge[tmp].target;
        if (target==father)
        {
            tmp=edge[tmp].next;
            continue;
        }
        if (!Visit[target]) DFS(target,x);
        low[x]=min(low[x],low[target]);
        tmp=edge[tmp].next;
    }
    return;
}

int main()
{
    freopen("1650.in","r",stdin);
    freopen("1650.out","w",stdout);

    scanf("%d%d",&n,&m);

    memset(last,-1,sizeof(last));

    for (int i=1,u,v;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        if (!map[u][v])
        {
            map[u][v]=map[v][u]=true;
            AddEdge(u,v);
            AddEdge(v,u);
        }
    }

    DFS(1,1);

    for (int i=1;i<=n;i++)
    {
        int tmp=last[i];
        while (tmp!=-1)
        {
            int target=edge[tmp].target;
            if (low[i]!=low[target]) Degree[low[i]]++;
            tmp=edge[tmp].next;
        }
    }

    int ans=0;
    for (int i=1;i<=n+1;i++)
        if (Degree[i]==1) ans++;
    printf("%d\n",(ans+1)/2);
    return 0;
}
