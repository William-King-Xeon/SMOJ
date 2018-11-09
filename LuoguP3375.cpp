#include <cstdio>
#include <cstring>

int next[1000005];
char a[1000005],b[1000005];

int main()
{
    scanf("%s\n%s",a,b);

    int lena=strlen(a),lenb=strlen(b);

    int j=-1; next[0]=-1;
    for (int i=1;i<lenb;i++)
    {
        while (j!=-1 && b[i]!=b[j+1]) j=next[j];
        if (b[i]==b[j+1]) j++;
        next[i]=j;
    }

    j=-1;
    for (int i=0;i<lena;i++)
    {
        while (j!=-1 && a[i]!=b[j+1]) j=next[j];
        if (a[i]==b[j+1]) j++;
        if (j==lenb-1)
        {
            printf("%d\n",i-lenb+2);
            j=next[j];
        }
    }

    for (int i=0;i<lenb;i++)
        printf("%d ",next[i]+1);

    return 0;
}
