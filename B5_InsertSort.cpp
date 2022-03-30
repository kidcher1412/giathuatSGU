#include<iostream>

using namespace std;

void InsertSort(int a[],int n)
{
    int i,j,key;
    for(int i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void insertsort(int a[],int n)
{
    int i,j,key;
    for(int i=1;i<n;i++)
    {
        key = a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1] =a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
    int a[] = {-4,-5,12,5,4,-5,8,-12,8,10,-2};
    int n = sizeof(a)/sizeof(int);
    insertsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}