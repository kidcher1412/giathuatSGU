#include<iostream>

using namespace std;


void mergesort(int a[],int l, int h)
{
    if(l<h)
    {
        int m = l+(h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}
void merge(int a[],int l, int m, int h)
{
    int i, j, k=l;
    int n1 = m-l+1;
    int n2= h-m;

    int L[n1], L[n2];

    for(i=0;i<n1;i++)
    {
        L[i] = a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]  = a[m+j+1];
    }
    i=0;j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        a[k++] = L[i]<=R[j] ? L[i++] : R[j++];
    }
    while(i<n1)
    {
        a[k++]= L[i++];
    }
    while(j<n2)
    {
        a[k++] = R[i++];
    }
}