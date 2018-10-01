#include<stdio.h>
#define max 64
typedef struct mat
{
	int a[max][max];
}m;
m strassen(m as,m bs,int s)
{
	int i,j;
	m m1;
	if(s==1)
	{
		m1.a[0][0]=as.a[0][0]*bs.a[0][0];
		return m1;
	}
	else
	{
		int i,j,k,l;
		m p1,p2,p3,p4,p5,p6,p7,a1,a2,a3,a4,b1,b2,b3,b4;
		
		for(i=0;i<s/2;i++)
		{
			for(j=0;j<s/2;j++)
			{
				a1.a[i][j]=as.a[i][j];
			}
		}
		for(i=s/2;i<s;i++)
		{
			for(j=0;j<s/2;j++)
			{
				a3.a[i-s/2][j]=as.a[i][j];
			}
		}
		for(i=0;i<s/2;i++)
		{
			for(j=s/2;j<s;j++)
			{
				a2.a[i][j-s/2]=as.a[i][j];
			}
		}
		for(i=s/2;i<s;i++)
		{
			for(j=s/2;j<s;j++)
			{
				a4.a[i-s/2][j-s/2]=as.a[i][j];
			}
		}
		for(i=0;i<s/2;i++)
		{
			for(j=0;j<s/2;j++)
			{
				b1.a[i][j]=bs.a[i][j];
			}
		}
		for(i=s/2;i<s;i++)
		{
			for(j=0;j<s/2;j++)
			{
				b3.a[i-s/2][j]=bs.a[i][j];
			}
		}
		for(i=0;i<s/2;i++)
		{
			for(j=s/2;j<s;j++)
			{
				b2.a[i][j-s/2]=bs.a[i][j];
			}
		}
		for(i=s/2;i<s;i++)
		{
			for(j=s/2;j<s;j++)
			{
				b4.a[i-s/2][j-s/2]=bs.a[i][j];
			}
		}
	
		m a12,a34,b12,b34,b24,a14,b14,a13,b13,a24;
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				a12.a[i][j]=a1.a[i][j]+a2.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				a34.a[i][j]=a3.a[i][j]+a4.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				b12.a[i][j]=b1.a[i][j]+b2.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				b34.a[i][j]=b3.a[i][j]+b4.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				b24.a[i][j]=b2.a[i][j]-b4.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				a14.a[i][j]=a1.a[i][j]+a4.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				b14.a[i][j]=b1.a[i][j]+b4.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				a13.a[i][j]=a1.a[i][j]-a3.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				b13.a[i][j]=b3.a[i][j]-b1.a[i][j];
			}
		for(i=0;i<s/2;i++)
			for(j=0;j<s/2;j++)
			{
				a24.a[i][j]=a2.a[i][j]-a4.a[i][j];
			}
		p1=strassen(a1,b24,s/2);		
		p2=strassen(a12,b4,s/2);		
		p3=strassen(a34,b1,s/2);		
		p4=strassen(a4,b13,s/2);		
		p5=strassen(a14,b14,s/2);		
		p6=strassen(a24,b34,s/2);
		p7=strassen(a13,b12,s/2);
		for(i=0;i<s/2;i++)
		{
			for(j=0;j<s/2;j++)
			{
				m1.a[i][j]=p5.a[i][j]+p4.a[i][j]+p6.a[i][j]-p2.a[i][j];
			}
		}
		for(i=0;i<s/2;i++)
		{
			for(j=s/2;j<s;j++)
			{
				m1.a[i][j]=p1.a[i][j-s/2]+p2.a[i][j-s/2];
			}
		}
		for(i=s/2;i<s;i++)
		{
			for(j=0;j<s/2;j++)
			{
				m1.a[i][j]=p3.a[i-s/2][j]+p4.a[i-s/2][j];
			}
		}	
		for(i=s/2;i<s;i++)
		{
			for(j=s/2;j<s;j++)
			{
				m1.a[i][j]=p1.a[i-s/2][j-s/2]+p5.a[i-s/2][j-s/2]-p3.a[i-s/2][j-s/2]-p7.a[i-s/2][j-s/2];;
			}
		}
		return m1;
		
	}
}
int main()
{
	int s[4],i,j,k,max1=0;
	m c,a1,b1;
	printf("Insert size of the 1st matrix\n");
	scanf("%d %d",&s[0],&s[1]);
	printf("\nEnter values in 1st matrix\n");

	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(i>=s[0] || j>=s[1])
				a1.a[i][j]=0;
			else
			{
				printf(" a(%d,%d):",i,j);
				scanf("%d",&a1.a[i][j]);
			}
		}

	}
	printf("Insert size of the 2nd matrix\n");
	while(1)
	{
		scanf("%d %d",&s[2],&s[3]);
		if(s[1]==s[2])
			break;
		printf("\n Input valid dimensions!!\n");
	}

	printf("\n Enter values in 2nd matrix\n");
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(i>=s[2] || j>=s[3])
				b1.a[i][j]=0;
			else
			{
				printf(" b(%d,%d):",i,j);
				scanf("%d",&b1.a[i][j]);
			}
		}
	}
	for(i=0;i<4;i++)
		if(s[i]>max1)
			max1=s[i];
	int t=1;
	while(1)
	{
		if(t>=max1)
			break;
		t*=2;
	}
	c=strassen(a1,b1,t);
	printf("\nMultiplied solution matrix :\n");
	for(i=0;i<s[0];i++)
	{
		for(j=0;j<s[3];j++)
		{
			printf("%d\t",c.a[i][j]);
			
		}
		printf("\n");
	}	
	return 0;
}
