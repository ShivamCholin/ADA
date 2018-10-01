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

void kruskal(int);


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
              temp.x=l.data[i].x;
              temp.y=l.data[i].y;
              temp.w=l.data[i].w;
              l.data[i].w=l.data[t].w;
              l.data[i].x=l.data[t].x;
              l.data[i].x=l.data[t].x;
              l.data[i].y=l.data[t].y;
              l.data[t].x=temp.x;
              l.data[t].y=temp.y;
              l.data[t].w=temp.w;
	      l.num++;
    }
        return l;
}



int main()
{

    int i,j;
    
    printf("enter no. of nodes : ");
    scanf("%d",&n );
    int e[n],k[n-1];
    int matrix[n][n];
    for(i=0;i<n;i++)
        e[i]=0;

   


    printf("enter matrix (NxN):");
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
   
	i=0;j=0;
	cs.num=0;
	kruskal(n);
	
    printf("\n\n List of all routes:\n");
    for(i=0;i<=cs.num;i++)
    {
	    printf("%d from %d to %d distance: %d\n",i+1,cs.data[i].x,cs.data[i].y,cs.data[i].w);
    }
					
}    
void kruskal(int n)
{
	int h;
	for(h=0;h<n;h++)
		belongs[h]=h;
	int i=0,f=0,l;
	cs.num=0;
	
	for(i=0;i<=ss.num;i++)
	{
		
		if(belongs[ss.data[i].x]!=belongs[ss.data[i].y])
		{	cs.data[cs.num].x=ss.data[i].x;
			cs.data[cs.num].y=ss.data[i].y;
			cs.data[cs.num].w=ss.data[i].w;
			
			cs.num++;
		
		int c=belongs[ss.data[i].x],c2=belongs[ss.data[i].y];
		for(f=0;f<=ss.num;f++)
		{
			if(belongs[f]==c)
				belongs[f]=c2;
		}
		}
	
	}
	cs.num--;
}
	
