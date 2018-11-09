#include <cstdio>

int n,m,faz[10005],z,x,y;

int GetRoot(int x)
{
    if (faz[x]==x) return x;
    return faz[x]=GetRoot(faz[x]);
}

int main()
{
    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++) faz[i]=i;

    while (m--)
    {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);

        x=GetRoot(x),y=GetRoot(y);
        if (z==1)
        {
            if (x!=y) faz[x]=y;
        } else
        {
            if (x!=y) printf("N\n");
                else printf("Y\n");
        }
    }

    return 0;
}
