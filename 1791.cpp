/*************************************************************************
	> File Name: 1791.cpp
	> Author: Xeon
	> Created Time: Mon 24 Apr 2017 09:12:11 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 1000000007

int n,m,k,f[35][35][512][10];

int DFS(int cur,int left,int set,int put)
{	
	if (cur==n) return !left;

	int &ans=f[cur][left][set][put];
	if (ans!=-1) return ans;

	ans=0;
	if (!(set&1)) ans=(ans+DFS(cur+1,left,set>>1,1))%MOD;
	
	for (int i=put;i<=k;i++)
	{
		if (cur+i>=n) break;
		if (!left) break;
		ans=(ans+DFS(cur,left-1,set^1^(1<<i),i))%MOD;
	}
	/* 
	 * Wrong??
	 * if (left) ans=(ans+DFS(cur,left-1,set^1^(1<<put),put))%MOD;
	 * if (put+1<=k&&cur+put+1<n) ans=(ans+DFS(cur,left,set,put+1))%MOD;
	*/

	return ans;
}

int main()
{
	freopen("1791.in","r",stdin);
	freopen("1791.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",DFS(0,m,0,1));
	return 0;
}
