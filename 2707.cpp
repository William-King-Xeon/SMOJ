#include <cstdio>
#include <iostream>

using namespace std;

#define int long long

int n,K,A[50],B[50],C[50],ans,sum1[50],sum2[50];

void DFS(int i,int k,int a,int b,int c)
{
    if (a+sum1[i]<=b) return;
    if (a+sum2[i]<=c) return;
    if (i>n)
    {
        if (k>K && a>b && a>c) ans++;
        return;
    }
    DFS(i+1,k,a,b,c);
    DFS(i+1,k+1,a+A[i],b+B[i],c+C[i]);
    return;
}

main()
{
    freopen("2707.in","r",stdin);
    freopen("2707.out","w",stdout);

    scanf("%lld%lld",&n,&K);

    for (int i=1;i<=n;i++) scanf("%lld",&A[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&B[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&C[i]);

    for (int i=n;i>=1;i--)
        sum1[i]=sum1[i+1]+max(A[i]-B[i],0LL);
    for (int i=n;i>=1;i--)
        sum2[i]=sum2[i+1]+max(A[i]-C[i],0LL);

    DFS(1,1,0,0,0);

    printf("%lld\n",ans);

    return 0;
}
