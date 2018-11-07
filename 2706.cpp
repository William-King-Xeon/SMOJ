#include <cstdio>

#define int long long

int n,m,sum[2005][2005];
char L[2005][2005];

int SUM(int a)
{
    return a*(a+1)/2;
}

main()
{
    freopen("2706.in","r",stdin);
    freopen("2706.out","w",stdout);
    
    scanf("%lld%lld",&n,&m);

    for (int i=0;i<n;i++)
        scanf("%s",&L[i]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+(L[i-1][j-1]=='#');

    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (L[i-1][j-1]!='#')
            {
                int b;
                for (b=j;b<=m;b++)
                    if (L[i-1][b-1]=='#') break;
                b--;
                ans+=SUM(b-j+1);
                for (int a=i+1;a<=n;a++)
                {
                    while (sum[a][b]-sum[a][j-1]!=0) b--;
                    if (b<j) break;
                    ans+=SUM(b-j+1)*(a-i+1);
                }
            }

    printf("%lld\n",ans);

    return 0;
}
