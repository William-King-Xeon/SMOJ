/*************************************************************************
	> File Name: 1792.cpp
	> Author: Xeon
	> Created Time: 2017年04月16日 星期日 19时35分11秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
int CntOne(int digit,int num)
{
	int cnt=0;
	for (int i=0;i<digit;i++)
		if ((num&(1<<i))) cnt++;
	return cnt;
}
int n,setsnum[20],Sets[20][65536];
long long f[65536][20];
bool CanWin[20][20];
int main()
{
	freopen("1792.in","r",stdin);
	freopen("1792.out","w",stdout);

	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		char Win[20];
		scanf("%s",Win);
		for (int j=0;j<n;j++)
			if (Win[j]=='Y') CanWin[i][j]=true;
				else CanWin[i][j]=false;
	}
	for (int i=1;i<(1<<n);i++)
	{
		int OneNum=CntOne(n,i);
		if (OneNum==1||OneNum==2||OneNum==4||
			OneNum==8||OneNum==16)
			Sets[OneNum][++setsnum[OneNum]]=i;
	}
	for (int i=0;i<n;i++) f[(1<<i)][i]=1;
	for (int a=2;a<=n;a*=2)
		for (int b=1;b<=setsnum[a];b++)
		{
			int set=Sets[a][b];
			for (int x=0;x<n;x++)
				if ((set&(1<<x)))
				{
					for (int c=1;c<=setsnum[a/2];c++)
					{
						int Lset=Sets[a/2][c];
						if ((Lset&set)!=Lset) continue;
						int Rset=set-Lset;
						if (Rset&(1<<x))
							for (int y=0;y<n;y++)
								if ((Lset&(1<<y))&&CanWin[x][y])
									f[set][x]+=f[Lset][y]*f[Rset][x]*2;
					}
				}
		}
	for (int i=0;i<n;i++) printf("%lld\n",f[(1<<n)-1][i]);
	return 0;
}
