#include<stdio.h>
void main()
{
	int n;
	printf("Enter no. of coins\n");
	scanf("%d",&n);
	int a[n],b[n],i,j,k,c,f=n-1;
	for( i=0;i<n;i++)
	{
		printf("\nenter coin no.%d ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		b[i]=0;
		for(j=0;j<n-1;j++)
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
	}	
	printf("\n Enter the required amount ");
	scanf("%d",&c);
	while(f>=0)
	{
		if(c>=a[f])
		{
			c-=a[f];
			b[f]++;
		}
		if(c<a[f])
		f--;
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d) no. of %d rupee coins =%d",i,a[i],b[i]);
	}
	printf("\n Remaining amount =%d",c);
}
