#include<iostream>
#include<stdio.h>

using namespace std;

int m[100];

int LuyThua(int a, int n){
    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        m[i] = m[i-1]*a;
    }
    return m[n];
}

int fib(int a){
    int u[100];
    u[0] = 1;
    u[1] = 1;
    for (int  i = 2; i <= a; i++)
    {
        u[i] = u[i-1] + u[i-2];
    }
    return u[a];

}
int main(){
    cout<<LuyThua(3,3);
    cout<<"\n"<<fib(3);
    return 0;
}