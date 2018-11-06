#include <cstdio>
#include <queue>

using namespace std;

struct EDGE
{
    int t,n,l;
} edge[500005];

int n,m,S[2000005],
    cur,last[505],
    f[505],InQueue[505];
queue<int> q;

void AddEdge(int u,int v,int w)
{
    cur++;
    edge[cur].t=v;
    edge[cur].n=last[u];
    edge[cur].l=w;
    last[u]=cur;
    return;
}

void BFS()
{
    q.push(1); f[1]=0; InQueue[1]=true;

    while (!q.empty())
    {
        int u=q.front(); q.pop(); InQueue[u]=false;
        for (int tmp=last[u];tmp;tmp=edge[tmp].n)
        {
            int v=edge[tmp].t,w=edge[tmp].l;
            if (S[f[u]]==w && f[u]+1>f[v])
            {
                f[v]=f[u]+1;
                if (!InQueue[v])
                    q.push(v),InQueue[v]=true;
            }
        }
    }
}

int main()
{
    freopen("2704.in","r",stdin);
    freopen("2704.out","w",stdout);

    S[0]=0,S[1]=1;

    for (int i=1;i<20;i++)
        for (int j=(1<<i);j<=(1<<i+1);j++)
            S[j]=1-S[j-(1<<i)];

    scanf("%d%d",&n,&m);

    for (int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        AddEdge(x,y,z);
    }

    BFS();

    int ans=0;
    for (int i=1;i<=n;i++)
        if (f[i]>ans) ans=f[i];
    printf("%d\n",ans);

    return 0;
}
