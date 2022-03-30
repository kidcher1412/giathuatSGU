#include<iostream>

using namespace std;
void mtsvc(int a[],int n)
{
    int tr,ph;
    int t,t1;
    t=INT16_MIN;
    for(int i=0;i<n;i++)
    {
        t1=0;
        for(int j=i;j<n;j++)
        {
            t1 += a[j];
            if(t1>t)
            {
                t=t1;
                tr=i;
                ph=j;
            }
        }
    }
    cout<<t<<endl;
    for(tr;tr<=ph;tr++)
    {
        cout<<a[tr]<<"\t";
    }
}
void mtsqhd(int a[],int n)
{
    int tr,ph;
    int t=a[0];
    int t1=a[0];
    for(int i=1;i<n;i++)
    {
        t1 = max(t1+a[i],a[i]);
        if(t1>t)
        {
            t=t1;
            ph=i;
        }
    }
    int tv = t;
    int k=ph;
    for(k;k>=0;k--)
    {
        tv=tv-a[k];
        if(tv==0)
        {
            tr=k;
            break;
        }
    }
    cout<<endl<<t<<endl;
    for(tr;tr<=ph;tr++)
    {
        cout<<a[tr]<<"\t";
    }
}

int trai,phai;
int mt(int a[],int i, int j)
{
    int t=INT16_MIN;
    int t1=0;
    for(int u=j;u>=i;u--){
        t1 = t1+a[u];
        if(t1>t)
        {
            t=t1;
            trai=u;
        }
    }
    return t;
}
int mp(int a[],int i, int j)
{
    int t=INT16_MIN;
    int t1=0;
    for(int v=i;v<=j;v++)
    {
        t1=t1+a[v];
        if(t1>t)
        {
            t=t1;
            phai=v;
        }
    }
    return t;
}
int mtscdt(int a[],int i, int j)
{
    if(i==j) return a[0];   
    int m =(i+j)/2;
    int maxt = mtscdt(a,i,m);
    int maxp = mtscdt(a,m+1,j);
    int maxh = mt(a,i,m)+ mp(a,m+1,j);;
    return max(max(maxt,maxp),maxh);
}
void maxtsCDT(int a[],int n){
    cout<<"Chia de tri: ---------------"<<endl;
    cout<<mtscdt(a,0,n-1)<<"\t";
    for(trai;trai<=phai;trai++)
    {
        cout<<a[trai]<<"\t";
    }
}
int main()
{
    int a[] = {-4,-5,12,5,4,-5,8,-12,8,10,-2};
    maxtsCDT(a, (sizeof(a)/sizeof(int)));
    cout<<endl<<"------------------------\n";
    mtsqhd(a, sizeof(a)/sizeof(int));
    cout<<endl<<"------------------------"<<endl;
    mtsvc(a, sizeof(a)/sizeof(int));
}