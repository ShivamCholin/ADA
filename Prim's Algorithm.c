#include<stdio.h>
#define N 100
static int belongs[N];
int n;
typedef struct edge1
{
    int x;
    int y;
    int w;
    
} edge;
typedef struct edgeList1
{
    edge data[N];
    int num;
} edgeList;
edgeList ss,cs;

void prims(int,int);


edgeList sortlist(edgeList l,int n)
{	
	int i,j;
	l.num=0;
    edge temp;
    for( i=0;i<n-1;i++)
    {
        int t=i;
        for( j=i;j<n;j++)
        {
            if(l.data[j].w<l.data[t].w)
                t=j;
        }
              temp=l.data[i];
              l.data[i]=l.data[t];
              l.data[t]=temp;
	      l.num++;
    }
        return l;
}



int main()
{
    int i,j,v;
    printf("enter no. of nodes : ");
    scanf("%d",&n );
    int matrix[n][n];
    printf("enter distance matrix (NxN):");
    ss.num=0;
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
          {
              if(i==j)
                matrix[i][i]=0;
              else
            {
              printf("\n Enter distance between %d and %d ",i,j);
              scanf("%d",&matrix[i][j]);
              matrix[j][i]=matrix[i][j];
              ss.data[ss.num].x=i;
              ss.data[ss.num].y=j;
              ss.data[ss.num].w=matrix[i][j];
              ss.num++;
            }
          }
    ss.num--;
    ss=sortlist(ss,ss.num+1);
    printf("\n Enter initial vertex ");
    scanf("%d",&v);
    i=0;j=0;
    cs.num=0;
    prims(n,v);
    printf("\n List of all routes:\n");
    for(i=0;i<=cs.num;i++)
    {
	    printf("%d from %d to %d distance: %d\n",i+1,cs.data[i].x,cs.data[i].y,cs.data[i].w);
    }					
}    
void prims(int n,int v)
{
	int h;
	for(h=0;h<n;h++)
		belongs[h]=0;
	
	int i=0,f=0,l,temp,echk[ss.num+1],t;
	for(i=0;i<=ss.num;i++)
		echk[i]=0;

	cs.num=0;
	belongs[v]=1;
	for(i=0;i<=ss.num;i++)
	{
	
		if(echk[i]==0 && (ss.data[i].y==v || ss.data[i].y==v))
		{
			temp=ss.data[i].x;
			ss.data[i].x=ss.data[i].y;
			ss.data[i].y=temp;
			echk[i]=1;

		}
		if(echk[i]==0 && (ss.data[i].x==v || ss.data[i].x==v))
		{
			echk[i]=1;
		}
	}

	while(cs.num<n-1)
	{	f=0;
		for(i=0;i<=ss.num;i++)
		{
			
			if(belongs[ss.data[i].y]==0 && echk[i]==1)
			{
				cs.data[cs.num].x=ss.data[i].x;
				cs.data[cs.num].y=ss.data[i].y;
				cs.data[cs.num].w=ss.data[i].w;
				cs.num++;
				belongs[ss.data[i].y]=1;
				f=1;
				echk[i]=2;
				

			
		
				for(t=0;t<=ss.num;t++)
				{
	
					if(echk[t]==0 && (ss.data[t].y==cs.data[cs.num-1].y))
					{
						temp=ss.data[t].x;
						ss.data[t].x=ss.data[t].y;
						ss.data[t].y=temp;
						echk[t]=1;

					}
					if(echk[t]==0 && (ss.data[t].x==cs.data[cs.num-1].y))
					{
						echk[t]=1;
					}
				}
			break;
			}	
			
		}
			
	}
	cs.num--;

}
	
