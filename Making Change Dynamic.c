#include<stdio.h>
void main()
{
	int n;
	printf("Enter no. of coins\n");
	scanf("%d",&n);
	int a[n],b[n+1],i,j,k,c,f=0;
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
	b[n]=0;
	printf("\n Enter the required amount ");
	scanf("%d",&c);
	int mat[n+1][c+1];
	int mata[n+1];
	mata[0]=0;
	for(i=0;i<c+1;i++)
		mat[0][i]=999;
	for(i=0;i<n+1;i++)
		mat[i][0]=0;
	for(i=0;i<n;i++)
		mata[i+1]=a[i];
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<c+1;j++)
		{
			if(i==1 && j<mata[i])
				mat[i][j]=999;
			else if(i==1)
				mat[i][j]=1+mat[i][j-mata[i]];
			else if(j<mata[i])
				mat[i][j]=mat[i-1][j];
			else
			{
				if(mat[i-1][j]>=1+mat[i][j-mata[i]])
					mat[i][j]=1+mat[i][j-mata[i]];
				else
					mat[i][j]=mat[i-1][j];
			}
		}
	}
	i=n;
	j=c;
	while(j>0)
	{
		if(mat[i][j]==999)
		{
			f=1;
			printf("\nNot possible with given denominations !!!!");
			break;
		}
		while(mat[i][j]==mat[i-1][j])
			i--;
		j-=mata[i];
		b[i]++;
	}

	if(f!=1)
	{
		for(i=0;i<n+1;i++)
		{
			printf("\n%d) no. of %d rupee coins =%d",i,mata[i],b[i]);
		}
	}
}
