#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int f[1000005][2],x,y,z,t,k,n,m,ans;
vector<int>edge[505],value[505];
string st,sr;
void dfs(int o,int lon){
	lon++;
	if(lon>(k<<1))k<<=1;
	if(lon<k) k>>=1;
	int siz=edge[o].size();
	for(int j=0;j<siz&&!t;j++){
		if(value[o][j]!=st[lon-k]-'0'){
			f[o][value[o][j]]=1;
			if(f[o][st[lon-k]-'0']==1){
				t=1;ans=-1;
			}
			sr=st;
			st+=(value[o][j]+'0');
			dfs(edge[o][j],lon);
			f[o][value[o][j]]=0;
			st=sr;
		}
	}
	if(!t)ans=max(ans,lon-1);	
}
int main(){
	freopen("2704.in","r",stdin);
	freopen("2704.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		edge[x].push_back(y);
		value[x].push_back(z);
	}
	k=1;
	st=" ";
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
