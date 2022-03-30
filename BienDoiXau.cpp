// Tính số bước biến đổi sao cho 2 chuỗi giống nhau vd: Saturday và sunday số bước biến đổi nhỏ nhất
// Chúng ta coi xóa, thêm, đổi chữ là 1 bước biến đổi.
#include <iostream>
using namespace std;
string s1="Trallll",s2="Traccccccccc";
int A[1000][1000],tmp;
void lapbang(){
    //cài đặt hàng đầu tiên bằng 0
    for (int i = 0; i <=s1.length(); ++i) A[0][i]=i;
    for (int i = 1; i <=s2.length(); ++i) {
        //cài đặt cột đầu tiên bằng 0
        A[i][0]=i;
        for (int j = 1; j <=s1.length() ; ++j) {
            tmp = (s1[j-1] == s2[i-1]) ? 0:1;
            A[i][j] = min(A[i-1][j-1]+tmp, min(A[i-1][j]+1,A[i][j-1]+1));
        }
    }
}
void hienbang(){
    cout<<"\nBang quy hoach: "<<endl;
    for (int i=0; i<=s2.length(); i++) {
        for (int j=0; j<=s1.length(); j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    lapbang();
    hienbang();
    cout<<endl<<"So buoc bien doi: "<<A[s2.length()][s1.length()]<<endl;
    return 0;
}