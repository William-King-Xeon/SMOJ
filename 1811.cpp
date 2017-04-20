/*************************************************************************
	> File Name: 1811.cpp
	> Author: Xeon
	> Created Time: 2017年04月20日 星期四 10时40分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int prime=10007;
int n,x[1005],y[1005];
struct _HASH
{
	int vlx,vly,cnt;
} _hash[prime];

int hash_push(int x,int y)
{
	int tmp=(x*x%prime+y*y%prime)%prime;
	while ((_hash[tmp].vlx!=x||_hash[tmp].vly!=y)&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	_hash[tmp].vlx=x;
	_hash[tmp].vly=y;
	return ++_hash[tmp].cnt;
}

int hash_find(int x,int y)
{
	int tmp=(x*x%prime+y*y%prime)%prime;
	while ((_hash[tmp].vlx!=x||_hash[tmp].vly!=y)&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	return _hash[tmp].cnt;
}

int main()
{
	freopen("1811.in","r",stdin);
	freopen("1811.out","w",stdout);
	scanf("%d",&n);
	while (n!=0)
	{
		memset(_hash,0,sizeof(_hash));
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			hash_push(x[i],y[i]);
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j)
				{
					int xdis=x[i]-x[j],ydis=y[i]-y[j];
					if (hash_find(x[i]-ydis,y[i]+xdis)&&hash_find(x[j]-ydis,y[j]+xdis))
						ans++;
					if (hash_find(x[i]+ydis,y[i]-xdis)&&hash_find(x[j]+ydis,y[j]-xdis))
						ans++;
				}
		printf("%d\n",ans/8);
		scanf("%d",&n);
	}
	return 0;
}
