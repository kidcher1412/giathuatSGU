#include<iostream>

using namespace std;



void merge(int a[],int l, int m, int h)
{
    int i,j,k=l;
    int n1 = m-l+1;;
    int n2= h-m;
    int L[n1], R[n2];

    //copy
    for(i=0;i<n1;i++)
    {
        L[i] = a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = a[m+j+1];
    }
    //tron
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        a[k++] = (L[i]<=R[i]) ? L[i++] : R[i++];
    };
    while(i<n1)
    {
        a[k++] = L[i++];
    }
    while(j<n2)
    {
        a[k++]= R[i++];
    }
}

void mergesort(int a[],int l, int h)
{
    if(l<h)
    {
        int m = l + (h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
} 
int main()
{
    int a[] = {-2,4,3,5,3,1,1,5,6,-199,6,7,4};
    int len = sizeof(a)/sizeof(int);
    printArray(a, len);
    cout<<"\n";
    mergesort(a,0,len-1);
    printArray(a,len);
    return 0;
}