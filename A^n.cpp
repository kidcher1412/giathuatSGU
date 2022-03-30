#include<iostream>
#include<stdio.h>

using namespace std;
int pow(int a, int n)
{
    if(n == 1) {
        return a;
    } else {
        int temp = pow(a, n/2);
        if(n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * a;
    }
}
int main(){
    cout<< pow(4,3);
}

// Dùng vòng for(i=0->n): O(n)

// Dùng chia để trị: T(n)= T(n/2)+O(1) => O(logn)