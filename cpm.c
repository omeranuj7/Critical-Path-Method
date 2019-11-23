#include<stdio.h>
struct Activity
{
char id;
int dur;
char pred[5];
int es;
int ef;
int ls;
int lf;
int floatval;
};
struct Activity act[8];

struct Activity2
{
char id;
int dur;
char pred[5];
int es;
int ef;
int ls;
int lf;
int floatval;
};
struct Activity2 act2[8];

int main()
{
	
int c;
printf("enter the no. of activities");
scanf("%d",&c);

int i,j,k,max,p=0;
printf("enter activity pred duration for forward pass\n");
for(i=0;i<c;i++)
{
	scanf("	%c",&act[i].id);
	scanf("	%s",&act[i].pred);
	scanf("	%d",&act[i].dur);
}

printf("enter activity pred duration for backword pass\n");
for(i=0;i<c;i++)
{
	scanf("	%c",&act2[i].id);
	scanf("	%s",&act2[i].pred);
	scanf("	%d",&act2[i].dur);
}

//forrward pass
for(i=0;i<c;i++)
{
if(act[i].pred[0]=='_')
{
act[i].es= 0;
act[i].ef=act[i].dur;
}
else
{
	max=0;
	for(j=0;act[i].pred[j]!=0;j++)
	{
		for(k=0;k<c;k++)
		{
			if(act[i].pred[j]==act[k].id)
		{
			if(act[k].ef>=max)
			{
				max = act[k].ef;
			}
		}
		}
		
	}
	act[i].es=max;
	act[i].ef=act[i].es+act[i].dur;
	if(p<act[i].ef)
		p=act[i].ef;
}
}


//backward pass

for(i=c-1;i>=0;i--)
{
if(act2[i].pred[0]=='_')
{
act2[i].ls= p-act2[i].dur;
act2[i].lf=p;
}
else
{
	int min=99999999;
	for(j=0;act2[i].pred[j]!=0;j++)
	{
		for(k=0;k<c;k++)
		{
			if(act2[i].pred[j]==act2[k].id)
		{
			if(act2[k].ls<=min)
			{
				min = act2[k].ls;
			}
		}
		}
		
	}
	act2[i].ls=min-act2[i].dur;
	act2[i].lf=min;
}
}


printf("\n");
printf("activity	earlystart	duration	earlyfinish	latestsStart	latestFinsish	float\n");
for(i=0;i<8;i++)
	printf("%c		%d		%d		%d		%d		%d		%d\n",act[i].id,act[i].es,act[i].dur,act[i].ef,act2[i].ls,act2[i].lf,act[i].es-act2[i].ls);
int tt=0;
printf("\n Critial Path is: \n");
for(i=0;i<8;i++)
	if(act[i].es-act2[i].ls==0)
	{
			printf("%c-->",act[i].id);
			tt+=act[i].dur;
	}
	
printf("\n%d is total critical path length",tt);
		




}
