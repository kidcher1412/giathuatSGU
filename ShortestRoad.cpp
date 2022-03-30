#include<iostream>

using namespace std;

#define max 100
#define false 0
#define true 1

int soDinh;
int chuaXet[max], truoc[max], hangDoi[max];
int first;
int last;
int A[max][max];

void khoiTao()
{
    cout<<"Nhap so dinh: ";
    cin>>soDinh;
    cout<<"\nBat dau: ";
    cin>>first;
    cout<<"\nKet thuc: ";
    cin>>last;
    cout<<"\nMa tran ke: ";
    for(int i=0;i<soDinh;i++)
    {
        for(int j=0;j<soDinh;j++)
        {
            cout<<"A["<<i<<"]"<<"["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<soDinh;i++)
    {
        chuaXet[i] = false;
        truoc[i] = -1;
    }
}
void BFS(int f)
{
    int dauQ, cuoiQ, u;
    dauQ =0;
    cuoiQ = 0;
    hangDoi[dauQ] = f;
    chuaXet[f] = false;

    while(dauQ<=cuoiQ)
    {
        u = hangDoi[dauQ];
        dauQ++;
        for(int v=0;v<soDinh;v++)
        {
            if(A[u][v]&&chuaXet[v]){
                cuoiQ++;
                hangDoi[cuoiQ] = v;
                chuaXet[v] = false;
                truoc[v] = u;
            }
        }
    }
}
void ketQua()
{
    if(truoc[last]==-1)
    {
        cout<<"Khong co!";
        return;
    }
    cout<<"Duog di: ";
    int j = last;
    cout<<last<<"<=";
    while(truoc[j]!=first){
        cout<<truoc[j]<<"<=";
        j = truoc[j];
    }
    cout<<first;
}
int main()
{
    khoiTao();
    BFS(first);
    ketQua();
}