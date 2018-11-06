#include <cstdio>

struct TREE
{
    int L,R,sum;
} tree[5000005];

int n,a[100005],last[100005],cnt,root[100005];

void Tree_Update(int &cur,int l,int r,int x,int y)
{
	if (l>x || r<x) return;
	tree[++cnt]=tree[cur];
	cur=cnt;
	if (l==r)
    {
        tree[cur].sum+=y;
        return;
    }
	int mid=(l+r)>>1;
	Tree_Update(tree[cur].L,l,mid,x,y);
	Tree_Update(tree[cur].R,mid+1,r,x,y);
    tree[cur].sum=tree[tree[cur].L].sum+
                  tree[tree[cur].R].sum;
    return;
}

int Tree_Query(int cur,int l,int r,int x)
{
    if (l==r)
    {
        if (x==0 && tree[cur].sum!=0) return l+1;
        return l;
    }
	int mid=(l+r)>>1;
    if (tree[tree[cur].R].sum>x)
        return Tree_Query(tree[cur].R,mid+1,r,x);
    else
        return Tree_Query(tree[cur].L,l,mid,x-tree[tree[cur].R].sum);
}

int main()
{
    freopen("2703.in","r",stdin);
    freopen("2703.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    for (int i=1;i<=n;i++)
    {
        root[i]=(i==1)?(1):(root[i-1]);
        if (last[a[i]]==0)
            Tree_Update(root[i],1,n,i,1);
        else
        {
            Tree_Update(root[i],1,n,last[a[i]],-1);
            Tree_Update(root[i],1,n,i,1);
        }
        last[a[i]]=i;
    }

    for (int i=1;i<=n;i++)
    {
        int ans=0,cur=n;
        while (cur)
        {
            cur=Tree_Query(root[cur],1,n,i)-1;
            ans++;
        }
        printf("%d ",ans);
    }

    printf("\n");

    return 0;
}
