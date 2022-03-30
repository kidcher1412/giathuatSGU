#include<iostream>
#include<conio.h>
using namespace std;
#define MAX  100 
#define TRUE  1 
#define FALSE  0
int n;//số đỉnh của đồ thị.
int truoc[MAX], chuaxet[MAX], queue[MAX];//mảng đánh dấu.
int A[MAX][MAX];// ma trận kề của đồ thị.
int s;//đỉnh đầu.
int t;//đỉnh cuối. 
using namespace std;
void khoiTao(void){ 
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n; 
    cout<<"Nhap dinh bat dau: ";
    cin>>s;
    cout<<"Nhap dinh dich: ";
    cin>>t;
    cout<<"Nhap ma tran ke cua do thi: \n";
    for(int i=0; i<n;i++){ 
        for(int j=0; j<n;j++){ 
            cout<<"A["<<i<<"]"<<"["<<j<<"]: ";
            cin>>A[i][j]; 
        }
    } 
    for(int i=0; i<n;i++){ 
        chuaxet [i] = TRUE; 
        truoc[i] = -1; 
    }    
} 
void Kq(void){ 
    if(truoc[t] == -1){ 
        cout<<"Khong co duong di tu "<<s<< " den "<<t; 
        return; 
    } 
    cout<<"Duong di tu "<<s<<" den "<<t<<" la: "; 
    int j = t;
    cout<<t<<"<="; 
    while(truoc[j] != s){ 
        cout<<truoc[j]<<"<="; 
        j=truoc[j]; 
    } 
    cout<<s; 
} 

void BFS(int s) { 
    int dauQ, cuoiQ, u;
    dauQ = 0;
    cuoiQ = 0;//khởi tạo queue.
    queue[dauQ] = s; //thêm đỉnh đầu vào queue.
    chuaxet[s] = FALSE; 
    while (dauQ <= cuoiQ){//queue chưa rỗng.
        u = queue[dauQ];//lấy đỉnh u trong queue.
        dauQ = dauQ+1; 
        for(int p = 0; p < n;p++){ 
            if(A[u][p] && chuaxet[p]){ 
                cuoiQ = cuoiQ+1;
                queue[cuoiQ] = p; 
                chuaxet[p] = FALSE;
                truoc[p] = u; 
            } 
        } 
    } 
    } 

int main(void){ 
    khoiTao();
    BFS(s); 
    Kq(); 
    return 0;
}