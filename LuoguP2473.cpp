#include <cstdio>
#include <iostream>

using namespace std;

int k,n,p[20],card[20];
double f[105][50005];

signed main()
{
    scanf("%d%d",&k,&n);

    for (int i=1,x;i<=n;i++)
    {
        scanf("%d%d",&p[i],&x);
        while (x!=0)
        {
            card[i]|=(1<<x-1);
            scanf("%d",&x);
        }
    }

    for (int i=k;i>=1;i--)
        for (int set=0;set<(1<<n);set++)
        {
            for (int j=1;j<=n;j++)
                if ((set&card[j])==card[j])
                    f[i][set]+=max(f[i+1][set],f[i+1][set|(1<<j-1)]+p[j]);
                else
                    f[i][set]+=f[i+1][set];
            f[i][set]/=n;
        }

    printf("%.6lf\n",f[1][0]);

    return 0;
}
