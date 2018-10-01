#include<stdio.h>
int br[10][2];
int ki[10][10];
int mcm(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        m[i][i] = 0;    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = 9999;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
		    ki[i][j]=k;
                }
            }
        }
    }
    return m[1][n-1];   
}
void putbr(int a,int b)
{
	if((b-a)>0)
	{
		putbr(a,ki[a][b]-1);
		putbr(ki[a][b],b);	
		br[a][1]++;
		br[ki[a][b]][1]++;
		br[ki[a][b]][2]++;
		br[b+1][2]++;
	}
}
void brisket(int n)
{
	int i=0,j;
	
	while(i<=n)
	{
		if(i!=0)
			printf("M%d",i);
		for(j=0;j<br[i][2]-1;j++)
			printf(")");
		if(i!=0 && i!=n)
			printf("*");
		for(j=0;j<br[i][1]-1;j++)
			printf("(");
		i++;
	}
}
int main()
{
    int n,i,j,m;
    printf("Enter number of matrices(MAX 9)\n");
    scanf("%d",&n);
    m=n+1;
    int arr[m];
    printf("Enter dimensions \n");
    for(i=0;i<m;i++)
    {
        printf("Enter d%d :: ",i);
        scanf("%d",&arr[i]);
	for(j=0;j<=n;j++)
	{
		ki[i][j]=0;
		br[i][1]=0;
		br[i][2]=0;
	}
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ",mcm(arr, size));
     for(j=0;j<n;j++)
    {
	    for(i=0;i<n+1;i++)
		ki[j-1][i-1]=ki[j][i];
    }
	putbr(0,n-1);
    printf("\n");
   brisket(n);
    return 0;
}
