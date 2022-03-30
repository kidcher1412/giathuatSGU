#include<iostream>
using namespace std;

void doiCho(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Sort(int a[],int n){
    int i, j, min;
    for(i=0;i<n-1;i++)
    {
        min =i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        doiCho(a[min],a[i]);
    }
}

void sls(int a[],int n)
{
    int i, j, min;
    for(i=0;i<n-1;i++)
    {
        min =i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        doiCho(a[min],a[i]);
    }
}
int main()
{
    int a[] = {-4,-5,12,5,4,-5,8,-12,8,10,-2};
    int n = sizeof(a)/sizeof(int);
    Sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}