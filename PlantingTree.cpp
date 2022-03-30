#include<iostream>

using namespace std;
void sort(int a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j <n; j++)
        {
            if(a[i]<a[j]){
                int t = a[j];
                a[j] =a[i];
                a[i] = t;
            }
        }
        
    }   
}
void plantingTree(int soHG, int soNgayNo[]){
    sort(soNgayNo, soHG);
    int res = 1, j = 1;
    for (int i = 0; i <soHG; i++)  
    {
        soNgayNo[i] += i;
        if (res < soNgayNo[i])
            res = soNgayNo[i];
    }
    res++;
    printf("%d\n", res);
}
int main(){
    int a[] = {8,8,8,8,8,8,8,8,8,8,8,7,7,2,8,8};
    // sort(a,5);
    // for(int i = 4 ; i>=0; i--){
    //     cout << "\t"<< a[i];
    // }
    // cout<<"\nTong so ngay can: " ;
    // plantingTree(5,a);
    
    sort(a,sizeof(a) / sizeof(int));
     for (int i =0;i<(sizeof(a) / sizeof(int));i++ )
      {
          cout<<"\t"<<a[i];
      }
      cout<<"\n";
      plantingTree(sizeof(a) / sizeof(int),a);
}