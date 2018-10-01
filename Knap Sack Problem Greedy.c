#include<stdio.h>
typedef struct item1
{	
	char name;
	int w;
	int p;
	float v;
	
}item;
void main()
{
	int n,i,j,k,ks;
	printf("Enter no. of items ");
	scanf("%d",&n);
	item list[n],temp;
	float a[n],profit=0;
	int f=0;
	for(i=0;i<n;i++)
	{
		list[i].name='A'+i;
		printf("\nEnter weight of item  %c =",'A'+i);
		scanf("%d",&list[i].w);
		printf("\nEnter profit of item  %c =",'A'+i);
		scanf("%d",&list[i].p);
		list[i].v=(float)list[i].p/(float)list[i].w;	
	}
	printf("\nEnter capacity of knapsack =");
	scanf("%d",&ks);

	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(list[j].v<list[j+1].v)
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
	printf("\n Choose method \n1)binary \n2)fraction \n  ");
	scanf("%d",&k);
	while(f<n)
	{
		if(ks>=list[f].w)
		{
			a[f]=1;
			ks-=list[f].w;
		}
		else if(ks<list[f].w)
		{
			if(k==2)
			{
				a[f]=(float)ks/list[f].w;
				ks=0;
			}
			else
			{
				a[f]=0;
			}
		}
		f++;
	}
	printf("Item name.\tweight\tprofit\tweight taken\t\tprofit recieved\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t\t%d\t%d\t%f\t\t%f\n",list[i].name,list[i].w,list[i].p,(float)a[i]*list[i].w,(float)a[i]*list[i].p);
		profit+=a[i]*(float)list[i].p;
	}
	printf("\nTotal profit =%f\n remaining space in knapsack = %d",profit,ks);

}
