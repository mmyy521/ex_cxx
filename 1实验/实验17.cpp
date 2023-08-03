#include<stdio.h>
int main()
{
	int n,flag=0,num=1,i,j,k,l,h;
	int a[8][8]={0},t=0; 
	while(scanf("%d",&n)!=EOF) 
	{  
		if(n==1)
		{
			printf("%d\n",1);
			continue;
		}
		int a[8][8]={0};
		num=1;
		flag=0; 
		t=0;				//0,n-1->n-1,n-1->n-1,0->0,0->0,n-2->n-2,n-2->
	while(flag==0&&t<=n-2)    				    //    +         -      -    +      +
	{
			for(k=t;k<n-t;k++)
			{      //1  1
				if(a[k][n-t-1]==0)
				{
					a[k][n-t-1]=num;//前加 
					num++;
				}
				else
				flag=1;	
			}
			if(flag==0)
			for(j=n-t-2;j>=t;j--)
			{
				if(a[n-t-1][j]==0)
				{
					a[n-t-1][j]=num;//后减 
				num++;
				}
				else
				flag=1;
				
			}
		if(flag==0)
		for(l=n-t-2;l>=t;l--)
		{
			if(a[l][t]==0)
			{
				a[l][t]=num;//前减 
			num++;
			}
			else
			flag=1;
		}
		if(flag==0&&n!=2) 
		for(h=t+1;h<n-t-1;h++)
		{
			if(a[t][h]==0)
			{
					a[t][h]=num;//后加 
			num++;
			}
			else
			flag=1;
		}
		t+=1;
	}
	for(i=0;i<n;i++)
	{
	
		for(j=0;j<n;j++)
		{
			if(j==n-1)
			printf("%d",a[i][j]);
			else
			printf("%d ",a[i][j]);
			
		}
		printf("\n");
		}
	}
 } 
