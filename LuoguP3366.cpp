#include <cstdio>
#include <algorithm>

using namespace std;

struct EDGE
{
    int u,v,w;
} e[200005];

int n,m,faz[5005];

bool Compare(EDGE a,EDGE b)
{
    return a.w<b.w;
}

int GetRoot(int x)
{
    if (faz[x]==x) return x;
    return faz[x]=GetRoot(faz[x]);
}

int main()
{
    scanf("%d%d",&n,&m);

    for (int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

    sort(e+1,e+1+m,Compare);

    for (int i=1;i<=n;i++) faz[i]=i;

    int cnt=0,ans=0;
    for (int i=1;i<=m;i++)
    {
        int a=GetRoot(e[i].u),b=GetRoot(e[i].v);

        if (a!=b)
        {
            faz[a]=b;
            ans+=e[i].w,cnt++;
            if (cnt==n-1) break;
        }
    }

    if (cnt!=n-1) printf("orz\n");
        else printf("%d\n",ans);

    return 0;
}
