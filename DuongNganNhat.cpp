#include<iostream>

using namespace std;

#define max 100;
#define false 0;
#define true 1;

int soDinh;
int first, last;
int hangDoi[max], chuaXet[max], truoc[max];
int A[max][max];

void khoiTao()
{
    cout<< "Nhap so dinh, dinh bat dau di, dinh can toi: ";
    cin>>soDinh>>first>>last;
    cout<<"Nhap ma tran: ";
    for (int i = 0; i < soDinh; i++)
    {
        for(int j=0;j<soDinh;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<soDinh;i++){
        chuaXet[i] = false;
        truoc[i] = -1;
    }
}

void BFSs(int f)
{
    int d,c,u;
    d=0;
    c=0;
    hangdoi[dau] = f;
    chuaxet[f] = false;

    while(d<=c)
    {
        u = hangDoi[d];
        d++;
        for(int v=0;v<soDinh;v++)
        {
            if(A[u][v]&&chuaXet[v]){
                c++;
                hangDoi[c] = v;
                chuaXet[v] = false;
                truoc[v] = u;
            }
        }

    }
}

void KQ()
{
    if(truoc[last]==-1)
    {
        cout<<"Noooooooooooo";
        return;
    }
    cout<<"Duong di: ";
    int j=last;

    while(truoc[j]!=first)
    {
        cout<<truoc[j];
        j = truoc[j];
    }
    cout<<first;
}













