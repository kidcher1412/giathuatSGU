#include<iostream>

using namespace std;

void InsertSort(int s[],int e[],int n)
{
      int key_s,key_e;
      for (int i = 1; i < n; i++)
      {
            key_s = s[i];
            key_e = e[i];
            int j = i-1;

            while (j>=0 && key_e<e[j])
            {
                  s[j+1] = s[j];
                  e[j+1] = e[j];
                  j--;
            }
            e[j+1] = key_e;
            s[j+1] = key_s;
      }}
void CongViec(int s[],int e[],int n){
      int end = e[0];
      int res = 1;
      for (int i = 1; i < n; i++)
      {
           if (end == e[i])
           {
                 continue;
           }
           if (end <= s[i])
           {
                 res++;
                 end = e[i];
           }         }      cout<<"So viec thuc hien duoc : "<<res;  
}
void PrintfArr(int a[],int n)
{
      for (int i = 0; i < n; i++)
      {
            cout<<a[i]<<"  ";
      }
      cout<<endl;  
}

int main(int argc, char const *argv[])
{
      int n;
      cout<<"So cong viec can thuc hien : ";
      cin>>n;

      int s[n],e[n];
      for (int i = 0; i < n; i++)
      {
            cout<<"Start : ";
            cin>>s[i];
            cout<<"End : ";
            cin>>e[i];
            cout<<"\n";
      }
      InsertSort(s,e,n);// sap xep theo thoi gian ket thuc

      cout<<"Start : ";PrintfArr(s,n);
      cout<<"End   : ";PrintfArr(e,n);
      CongViec(s,e,n);

      
      return 0;
}
