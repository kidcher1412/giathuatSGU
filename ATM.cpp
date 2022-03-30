#include<iostream>
#include<math.h>

using namespace std;

void rutTien(int w, int c){

    int soMG = c*4 +4;
    int menhGia[soMG]={1000, 2000, 3000, 5000};
    int k = 4;
    int soTo=0;
    int st=0;
    if(c>=1)
        for(int i=1;i<=c;i++)
        {
            menhGia[k] = 1000*pow(10,i);
            menhGia[k+1] = 2000*pow(10,i);
            menhGia[k+2] = 3000*pow(10,i);
            menhGia[k+3] = 5000*pow(10,i);
            k+=4;
        }
    cout<< "Cac menh gia: (VND) \n";
    for (int i = 0; i < soMG; i++)
    {
        cout<<"\t"<<menhGia[i];
    }
    cout<<"\nSo tien can rut: "<<w<<"\n";
    cout<<"So to cung menh gia nhan duoc: \n";
    for (int i = soMG-1; i >=0; i--)
    {
        if(w>=menhGia[i]){
            soTo = w/menhGia[i];
            st = st +soTo;
            cout<<"\n"<<soTo<<" to "<<menhGia[i]<< " VND";
            w -= soTo*menhGia[i];
        }
    }
    cout<<"\nTong so to it nhat nhan duoc:   "<<st<<" to!";
}
int main()
{
    rutTien(2239000,5);
}