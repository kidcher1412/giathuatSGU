#include<iostream>

using namespace std;

#define MAX  100 
#define TRUE  1 
#define FALSE  0
int s=0;
int n;//số đỉnh của đồ thị.
int  chuaxet[MAX], queue[MAX];//mảng đánh dấu.
int A[MAX][MAX];// ma trận kề của đồ thị.
int st;//đỉnh đầu.
int t;//đỉnh cuối. 
using namespace std;
void khoiTao(void){ 
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n; 
    cout<<"Nhap dinh bat dau: ";
    cin>>st;
    cout<<"Nhap dinh dich: ";
    cin>>t;
    cout<<"Nhap ma tran ke cua do thi: \n";
    for(int i=0; i<n;i++){ 
        for(int j=0; j<n;j++){ 
            cout<<"A["<<i<<"]"<<"["<<j<<"]: ";
            cin>>A[i][j]; 
        }
    }    
} 
void BFS(int f)
{
    int dau, cuoi;
    int u;
    queue[dau] = f;
    s++;
    chuaxet[f] = s;
    while(dau<=cuoi)
    {
        u = queue[dau];
        dau++;
        for(int v=0;v<n;v++)
        {
            if(chuaxet[v])
            {
                cuoi++;
                chuaxet[v] = s;
                queue[cuoi] = v;
            }
        }
    }
}
void Lien_Thong(void){

 for (int i=1; i<=n; i++)
  chuaxet[i] =0;

 for(int i=1; i<=n; i++)
  if(chuaxet[i]==0){

   s=s+1;

   BFS(i);

  }

}
void Result( int s){

 if (s==1){

  cout<<"Lien Thong";

 }

 for(int i=1; i<=s;i++){

  /* Đưa ra thành phần liên thông thứ i*/

  for(int j=1; j<=n;j++){

   if( chuaxet[j]==i)

    cout<<"\t"<<j;

  }

 }

}
int main()
{
    khoiTao();
    Lien_Thong();
    Result(s);
}