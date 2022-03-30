#include<stdio.h>
#define N 10000
int a=500; 
int b=1500;
int c=500;

typedef struct state
{
	int A;
	int B;
}state;

typedef struct Queue
{
	int first, last;
	int size;
	state elems[N];
}Queue;

int init(Queue *Q)
{
	(*Q).size=0;
	Q->last=-1;
	Q->first=0;
}

void enqueue(state x, Queue *Q)
{
	if (Q->size<N) 
	{
		Q->size ++;
		Q->last =(Q->last+1)%N;
		Q->elems[Q->last].A =x.A ;
		Q->elems[Q->last].B =x.B ;
	}
	else printf("\n Hang doi day!");
}

void dequeue(Queue *Q, state *x)
{
	if(Q->size>0)
	{
		(*x).A =Q->elems[Q->first].A ;
		(*x).B =Q->elems[Q->first].B ;
		Q->first=(Q->first+1)%N;
		Q->size--;
		
	}
	else printf("\n Hang doi rong!");
}

int ktbangnhau(state x, state y)
{
	if ((x.A ==y.A )&&(x.B ==y.B )) return 1;
	else return 0;
}

state dohetnuocbinhA(state x)
{
	x.A =0;
	return x;
}

state dohetnuocbinhB(state x)
{
	x.B=0;
	return x;
}

state dodaybinhA(state x)
{
	x.A =a;
	return x;
}

state dodaybinhB(state x)
{
	x.B =b;
	return x;
}

state rottubinhAsangB(state x)
{ state y;
	if (x.A+x.B <b) 
	{
		y.A =0;
		y.B=x.A +x.B ;
	}
	else 
	{
		y.A =x.A +x.B -b;
		y.B =b;
	}
	return y;
}

state rottubinhBsangA(state x)
{
	state y;
	if (x.A +x.B <a)
	{
		y.A =x.A +x.B ;
		y.B =0;
	}
	else
	{
		y.A=a;
		y.B =x.A +x.B -a;
	}
	return y;
}

int main()
{
int kt;
state dinh[N];
//int mark[N];
int truoc[N];// mang luu buoc truoc 

int i=0;
Queue Q;

state x;

x.A =0;
x.B =0;
init(&Q);
enqueue(x,&Q);
//i++;
dinh[1].A =x.A ;
dinh[1].B =x.B ;
truoc[1]=0;
int cuoi;
int k=1;

while (Q.size >0)
{
	state y1,y2,y3,y4,y5,y6;
	//int k;
	//int kt;
	
	dequeue(&Q,&x);
	i++;
	//dinh[i].A =x.A ;
	//dinh[i].B =x.B ;
	//mark[i]=1;
	
	y1=dohetnuocbinhA(x);
	kt=1;// kiem tra trang thai y1 da xuat hien trong do thi chua
	for (int j=1;j<=k;j++)
	{ //int kt=1;
		if (ktbangnhau(y1,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1) 
	{
	//enqueue(y1,&Q);
	k++;
    dinh[k].A =y1.A ;
    dinh[k].B =y1.B ;
    truoc[k]=i;
	if ((y1.A ==c)||(y1.B ==c))
	{
		cuoi=k;
		break;
	}
	
	else enqueue(y1,&Q);
	}
	
	y2=dohetnuocbinhB(x);
	kt=1;
	for (int j=1;j<=k;j++)
	{ 
	if (ktbangnhau(y2,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1) 
	{
	k++;
    dinh[k].A =y2.A ;
    dinh[k].B =y2.B ;
    truoc[k]=i;
    if( (y2.A ==c)||(y2.B ==c) )
    {
		cuoi=k;
		break;
	}
    else enqueue(y2,&Q);
	}
	
	y3=dodaybinhA(x);
	kt=1;
	for (int j=1;j<=k;j++)
	{ //int kt=1;
		if (ktbangnhau(y3,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1) 
	{
	
	k++;
    dinh[k].A =y3.A ;
    dinh[k].B =y3.B ;
    truoc[k]=i;
	if ((y3.A ==c)||(y3.B ==c))
	{
		cuoi=k;
		break;
	}
	else 
	enqueue(y3,&Q);
	}
	
	y4=dodaybinhB(x);
	kt=1;
	for (int j=1;j<=k;j++)
	{ //int kt=1;
		if (ktbangnhau(y4,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1) 
	{
	k++;
    dinh[k].A =y4.A ;
    dinh[k].B =y4.B ;
    truoc[k]=i;
    if ( (y4.A ==c)||(y4.B ==c) )
    {
		cuoi=k;
		break;
	}
    else enqueue(y4,&Q);
	}
	
	y5=rottubinhAsangB(x);
	kt=1;
	for (int j=1;j<=k;j++)
	{ //int kt=1;
		if (ktbangnhau(y5,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1)
	{
		k++;
    	dinh[k].A =y5.A ;
    	dinh[k].B =y5.B ;
    	truoc[k]=i;
		if ((y5.A ==c)||(y5.B ==c))
		{
		cuoi=k;
		break;
	    }
		else enqueue(y5,&Q);
	 } 
	
	y6=rottubinhBsangA(x);
	kt=1;
	for (int j=1;j<=k;j++)
	{ //int kt=1;
		if (ktbangnhau(y2,dinh[j])==1) 
		{
			kt=0;
			break;
		}
	}
	if (kt==1) 
	{
	k++;
    dinh[k].A =y6.A ;
    dinh[k].B =y6.B ;
    truoc[k]=i;
    if ((y6.A ==c)||(y6.B ==c)) 
	{
		cuoi=k;
		break;
	}
	else enqueue(y6,&Q);	
	}
}

printf("\n so dinh= %d",k);
printf("\n dinh cuoi=%d", cuoi);
// in duong di, in cac phuong an rot
while (truoc[cuoi]!=0) 
{
printf("\n %5d %5d", dinh[cuoi].A , dinh[cuoi].B );
cuoi=truoc[cuoi];	
} 

return 1;
}
