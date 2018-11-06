#include <cstdio>

int n,m,S[2000005];

void BFS()

int main()
{
    //freopen("2704.in","r",stdin);
    //freopen("2704.out","w",stdout);

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

    printf("%d\n",ans);

    return 0;
}
