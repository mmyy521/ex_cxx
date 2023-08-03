#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	char str[n][100];
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		a[i]=strlen(str[i]);
	}
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<=a[k]/2;j++)
		{
			if(str[k][j]!=str[k][a[k]-j-1])
			{
				a[k]=0;
				continue;
			}	
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++) 
		{
				if(a[j]>a[j+1]) 
				{
					int t;
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
					char b[100];
					strcpy(b,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],b);					
				}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		printf("%s\n",str[i]);
	}
}
