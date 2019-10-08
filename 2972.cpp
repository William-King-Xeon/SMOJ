%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")

#include <cstdio>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

struct TREE
{
    double Min,Max;
} tree[400005];

int n;
double a[100005];

void Tree_Build(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur].Min=a[l];
        tree[cur].Max=a[l];
        return;
    }
    int mid=(l+r)/2;
    Tree_Build(cur*2,l,mid);
    Tree_Build(cur*2+1,mid+1,r);
    tree[cur].Min=MIN(tree[cur*2].Min,tree[cur*2+1].Min);
    tree[cur].Max=MAX(tree[cur*2].Max,tree[cur*2+1].Max);
    return;
}

TREE Tree_Query(int cur,int l,int r,int s,int t)
{
    if (s<=l && r<=t) return tree[cur];
    if (r<s || l>t) return (TREE){1000005,0};
    int mid=(l+r)/2;
    TREE Left=Tree_Query(cur*2,l,mid,s,t),
         Right=Tree_Query(cur*2+1,mid+1,r,s,t);
    return (TREE){MIN(Left.Min,Right.Min),MAX(Left.Max,Right.Max)};
}

int main()
{
    freopen("2972.in","r",stdin);
    freopen("2972.out","w",stdout);

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
    Tree_Build(1,1,n);

    for (int i=2;i<=n;i++)
    {
        double ans=1000005;
        for (int j=1;j+i-1<=n;j++)
        {
            TREE curans=Tree_Query(1,1,n,j,j+i-1);
            ans=MIN(ans,curans.Max-curans.Min);
        }
        printf("%.5lf\n",ans);
    }

    return 0;
}
