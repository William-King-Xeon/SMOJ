#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

#define int long long
#define INF 20000000000LL

struct EDGE
{
    int t,n,l;
} edge[1000005];

int n,m,t[2005][205],dis[400005],
    cur,last[400005];
bool InQueue[400005];
queue<int> q;

void AddEdge(int u,int v,int w)
{
    ++cur;
    edge[cur].t=v;
    edge[cur].n=last[u];
    edge[cur].l=w;
    last[u]=cur;
    return;
}

main()
{
    freopen("2705.in","r",stdin);
    freopen("2705.out","w",stdout);

    scanf("%lld%lld",&n,&m);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%lld",&t[i][j]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (j==1 || j==m)
            {
                if (i!=1) AddEdge((i-1)*m+j,(i-2)*m+j,t[i][j]);
                if (i!=n) AddEdge((i-1)*m+j,i*m+j,t[i][j]);
            }
            if (j!=1) AddEdge((i-1)*m+j,(i-1)*m+j-1,t[i][j]);
            if (j!=m) AddEdge((i-1)*m+j,(i-1)*m+j+1,t[i][j]);
        }

    int k,X,Y,curx=1,cury=1,ans=0;
    scanf("%lld",&k);
    while (k--)
    {
        scanf("%d%d",&X,&Y);

        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                dis[(i-1)*m+j]=INF;
        dis[(curx-1)*m+cury]=0;

        q.push((curx-1)*m+cury); InQueue[(curx-1)*m+cury]=true;
        while (!q.empty())
        {
            int u=q.front(); q.pop(); InQueue[u]=false;
            for (int tmp=last[u];tmp;tmp=edge[tmp].n)
            {
                int v=edge[tmp].t;
                if (dis[u]+edge[tmp].l<dis[v])
                {
                    dis[v]=dis[u]+edge[tmp].l;
                    if (!InQueue[v])
                    {
                        InQueue[v]=true;
                        q.push(v);
                    }
                }
            }
        }

        ans+=dis[(X-1)*m+Y];
        curx=X,cury=Y;
    }

    printf("%lld\n",ans+t[curx][cury]);

    return 0;
}
