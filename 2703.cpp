#include <cstdio>

int n,a[100005],lastk,k,cur,sign[100005];

int main()
{
    freopen("2703.in","r",stdin);
    freopen("2703.out","w",stdout);
    
    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    for (int i=1;i<=n;i++)
    {
        lastk=k++; cur=0;
        for (int j=1;j<=n;j++)
            if (sign[a[j]]!=k)
            {
                if (cur<i) cur++; else k++,cur=1;
                sign[a[j]]=k;
            }
        printf("%d ",k-lastk);
    }
    printf("\n");

    return 0;
}
