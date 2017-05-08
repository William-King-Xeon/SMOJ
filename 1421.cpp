/*************************************************************************
	> File Name: 1421.cpp
	> Author: Xeon
	> Created Time: 2017年04月26日 星期三 14时52分21秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct TREE
{
	int color;
	bool change;
} tree[1600005];

void Down(int cur);
void Tree_Update(int cur,int l,int r,int s,int e,int x);
int  Tree_Find(int cur,int l,int r,int x);

int n,s,x[200005],y[200005],f[200005][2],DOWN[200005][2];

int main()
{
	freopen("1421.in","r",stdin);
	freopen("1421.out","w",stdout);

	scanf("%d%d",&n,&s);

	int S=s+100001;

	x[0]=100001;
	y[0]=(100001*2)-1;
	x[n+1]=S;
	y[n+1]=S;

	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",&x[i],&y[i]);

		x[i]+=100001;y[i]+=100001;

		DOWN[i][0]=Tree_Find(1,1,200001,x[i]);
		DOWN[i][1]=Tree_Find(1,1,200001,y[i]);

		Tree_Update(1,1,200001,x[i],y[i],i);
	}

	DOWN[n+1][0]=n;
	DOWN[n+1][1]=n;

	for(int i=1;i<=n+1;i++)
		f[i][0]=min(f[DOWN[i][0]][0]+abs(x[i]-x[DOWN[i][0]]),f[DOWN[i][0]][1]+abs(x[i]-y[DOWN[i][0]])),
		f[i][1]=min(f[DOWN[i][1]][0]+abs(y[i]-x[DOWN[i][1]]),f[DOWN[i][1]][1]+abs(y[i]-y[DOWN[i][1]]));

	printf("%d\n",f[n+1][0]);
	return 0;
}

void Down(int cur)
{
	int Left=cur*2,Right=cur*2+1;

	tree[Left].color=tree[cur].color;
	tree[Left].change=true;

	tree[Right].color=tree[cur].color;
	tree[Right].change=true;

	tree[cur].change=false;
	return;
}

void Tree_Update(int cur,int l,int r,int s,int e,int x)
{
	if (l>r) return;
	if (s>r||e<l) return;

	if (s<=l&&r<=e)
	{
		tree[cur].color=x;
		tree[cur].change=true;
		return;
	}

	if (tree[cur].change) Down(cur);

	int mid=(l+r)/2;
	Tree_Update(cur*2,l,mid,s,e,x);
	Tree_Update(cur*2+1,mid+1,r,s,e,x);
	return;
}

int Tree_Find(int cur,int l,int r,int x)
{
	if (l>r) return -1;
	if (x<l||x>r) return -1;

	if (tree[cur].change) Down(cur);
	if (l==x&&r==x) return tree[cur].color;

	int mid=(l+r)/2;
	int Left=Tree_Find(cur*2,l,mid,x),
		Right=Tree_Find(cur*2+1,mid+1,r,x);

	if (Left!=-1) return Left;
		else return Right;
}
