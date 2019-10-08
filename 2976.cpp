#include <cstdio>
#include <algorithm>

#define MAX(a,b) ((a)>(b)?(a):(b))

struct EDGE
{
    int t,n;
} edge[1000005];

int n,p,q,T[3],op[1000005],root[1000005],
    cur,last[1000005],
    cnt,stack[1000005];
char s[1000005];

void AddEdge(int u,int v)
{
    cur++;
    edge[cur].t=v;
    edge[cur].n=last[u];
    last[u]=cur;
    return;
}

int Cnt(int l,int r,int add)
{
    if (l==r) return stack[l];
    int mid=(l+r)/2;
    return MAX(Cnt(l,mid,add),Cnt(mid+1,r,add))+add;
}

void DFS(int u,int lastop)
{
    if (op[u]==0)
    {
        stack[++cnt]=0;
        return;
    }
    int oldcnt=cnt;
    for (int tmp=last[u];tmp;tmp=edge[tmp].n)
    {
        int v=edge[tmp].t;
        DFS(v,op[u]);
    }
    if (op[u]!=lastop)
    {
        std::sort(stack+1+oldcnt,stack+1+cnt);
        int ret=Cnt(oldcnt+1,cnt,T[op[u]]);
        cnt=oldcnt;
        stack[++cnt]=ret;
    }
    return;
}

int main()
{
    freopen("2976.in","r",stdin);
    freopen("2976.out","w",stdout);

    scanf("%d%d%d",&n,&T[1],&T[2]);
    scanf("%s",s);

    for (int i=0;i<n-1;i++)
        if (s[i]=='+') op[i+1]=1;
            else op[i+1]=2;

    for (int i=1;i<2*n;i++) root[i]=true;
    for (int i=1,u,v;i<=2*n-2;i++)
    {
        scanf("%d%d",&u,&v);
        AddEdge(u,v);
        root[v]=false;
    }

    int rt=0;
    for (int i=1;i<2*n;i++)
        if (root[i]) { rt=i; break; }

    DFS(rt,0);
    printf("%d\n",stack[1]);

    return 0;
}
