#include<stdio.h>
typedef struct item1
{	
	char name;
	int w;
	int p;
	
	
}item;
void main()
{
	int n,i,j,ks;
	printf("Enter no. of items ");
	scanf("%d",&n);
	item list[n];
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=0;
		list[i].name='A'+i;
		printf("\nEnter weight of item  %c =",'A'+i);
		scanf("%d",&list[i].w);
		printf("\nEnter profit of item  %c =",'A'+i);
		scanf("%d",&list[i].p);
		
	}
	
	printf("\nEnter capacity of knapsack =");
	scanf("%d",&ks);
	int mat[n+1][ks+1];
	for(i=0;i<n+1;i++)
		mat[i][0]=0;
	for(i=0;i<ks+1;i++)
		mat[0][i]=0;
	for(i=1;i<n+1;i++)
	{	for(j=1;j<ks+1;j++)
		{
			if(j<list[i-1].w)
				mat[i][j]=mat[i-1][j];
			else
			{
				if(mat[i-1][j]>=list[i-1].p+mat[i-1][j-list[i-1].w])
					mat[i][j]=mat[i-1][j];
				else
					mat[i][j]=list[i-1].p+mat[i-1][j-list[i-1].w];
			}
		}	
	}
	i=n;
	j=ks;
	while(i>0)
	{
		while(mat[i][j]==mat[i-1][j])
			i--;
		a[i-1]=1;
		j-=list[i-1].w;
		i--;
	}
	
	printf("\n\nItems taken =\nItem name.\tweight\tprofit\n");
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		printf("%c\t\t%d\t%d\n",list[i].name,list[i].w,list[i].p);		
	}
	printf("\nTotal profit =%d",mat[n][ks]);
	
	

}
