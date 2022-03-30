#include <iostream>
using namespace std;
int a, b;
int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a % b);
  }
void show(int a, int b){
  cout << a << "\t" << b<<endl;
}
void TimKiem(int n){
  int xq = 0, yq = 0; // mực nước hiện tại của a và b
  show(xq,yq);
  int t;
  while (xq != n && yq!= n )  {
    if (xq == 0){ //nếu a rỗng
      xq = a; // đổ đầy a
      show(xq, yq); 
    }else 
        if(yq == b){ // nếu b đầy
          yq = 0; // đổ hết b đi
          show(xq, yq);  
        }else{    // nếu b không đầy
          t = min(b - yq, xq);    
          yq= yq + t;
          xq = xq - t;
          show(xq, yq);          
          }
    }
    show(xq,yq);
}
int main(){
    int c; 
    cin >> c;
    cin >> a >> b;  
    if(c<a || c<b)    {  
        if(c%(gcd(a,b))==0) TimKiem(c);    //nếu thể tích c chia hết cho UCLN của thể tích a,b thì có thể tìm các bước
        else cout<<"Ko chia dc\n";    }
    else cout<<"Ko chia dc\n";
}