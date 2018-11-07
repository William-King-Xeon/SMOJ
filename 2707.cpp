#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long
#define INF 40000000000LL

struct PROGRAM
{
    int ab,ac;
} p1[500005],p2[500005];

struct TREE
{
    int l,r,sum;
} tree[5000005];

int n,K,A[50],B[50],C[50],illegal,
    cnt1,cnt2,TREECNT=1;

bool Compare1(PROGRAM a,PROGRAM b)
{
    return a.ab<b.ab;
}

bool Compare2(PROGRAM a,PROGRAM b)
{
    return a.ab>b.ab;
}

void DFS_Illegal(int i,int k,int a,int b,int c)
{
    if (k>K) return;
    if (i>n)
    {
        if (a>b && a>c) illegal++;
        return;
    }
    DFS_Illegal(i+1,k,a,b,c);
    DFS_Illegal(i+1,k+1,a+A[i],b+B[i],c+C[i]);
    return;
}

void DFS1(int i,int a,int b,int c)
{
    if (i>n/2)
    {
        p1[++cnt1].ab=a-b,
        p1[cnt1].ac=a-c;
        return;
    }
    DFS1(i+1,a,b,c);
    DFS1(i+1,a+A[i],b+B[i],c+C[i]);
    return;
}

void DFS2(int i,int a,int b,int c)
{
    if (i>n)
    {
        p2[++cnt2].ab=a-b;
        p2[cnt2].ac=a-c;
        return;
    }
    DFS2(i+1,a,b,c);
    DFS2(i+1,a+A[i],b+B[i],c+C[i]);
    return;
}

void Tree_Update(int cur,int l,int r,int x)
{
    if (l==x && r==x)
    {
        tree[cur].sum+=1;
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid)
    {
        if (!tree[cur].l) tree[cur].l=++TREECNT;
        Tree_Update(tree[cur].l,l,mid,x);
    } else
    {
        if (!tree[cur].r) tree[cur].r=++TREECNT;
        Tree_Update(tree[cur].r,mid+1,r,x);
    }
    tree[cur].sum=tree[tree[cur].l].sum+
                  tree[tree[cur].r].sum;
    return;
}

int Tree_Query(int cur,int l,int r,int s,int t)
{
    if (cur==0) return 0;
    if (r<s || l>t) return 0;
    if (s<=l && r<=t) return tree[cur].sum;
    int mid=(l+r)/2;
    return Tree_Query(tree[cur].l,l,mid,s,t)+
           Tree_Query(tree[cur].r,mid+1,r,s,t);
}

main()
{
    freopen("2707.in","r",stdin);
    freopen("2707.out","w",stdout);

    scanf("%lld%lld",&n,&K);

    for (int i=1;i<=n;i++) scanf("%lld",&A[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&B[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&C[i]);

    DFS_Illegal(1,1,0,0,0);

    DFS1(1,0,0,0);
    DFS2(n/2+1,0,0,0);

    sort(p1+1,p1+1+cnt1,Compare1);
    sort(p2+1,p2+1+cnt2,Compare2);

    int j=1,ans=0;
    for (int i=1;i<=cnt1;i++)
    {
        while (p1[i].ab+p2[j].ab>0 && j<=cnt2)
        {
            Tree_Update(1,0,2*INF,p2[j].ac+INF);
            j++;
        }
        ans+=Tree_Query(1,0,2*INF,0-p1[i].ac+1+INF,2*INF);
    }

    printf("%lld\n",ans-illegal);
    return 0;
}
