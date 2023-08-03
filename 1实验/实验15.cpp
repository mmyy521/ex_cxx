#include<stdio.h>    
int main()
{
	int n,m,f=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n>m)
	{
        int t = n;
        n = m;
        m = t;
    }
    int i;
    for(i=2;i<n;i++)
    {
    	if(n%i==0&&m%i==0)
    	f=1;
	}
      if(f==1)
      printf("No");
      else
      printf("Yes");
 }
}



