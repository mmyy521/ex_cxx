#include<stdio.h>
#include<string.h> 
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	int a[1000]={0};
	for(i=2;i<=k;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(j%i==0)
			{
				if(a[j]==0)
				a[j]=1;
				else
				a[j]=0;
			} 
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
        {
		printf("%d ",i);
        }
	}
}
