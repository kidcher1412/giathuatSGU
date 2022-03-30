#include<iostream>
using namespace std;
int tralol,tienlol;
int Lon_Nhat_Trai (int a[], int i, int j)
	{
		int Tong_LonNhat = INT16_MIN;
		int Tong = 0;
		for (int v = j; v >= i; v--){
			Tong = Tong + a[v];
			Tong_LonNhat = max(Tong, Tong_LonNhat);			
		}
		return Tong_LonNhat;
	}
	//Tìm tổng dãy con lớn nhất bên phải
	int Lon_Nhat_Phai (int a[], int i, int j){
		int Tong_LonNhat = INT16_MIN;
		int Tong = 0;
		for (int v = i; v <= j; v++){
			Tong = Tong + a[v];
			Tong_LonNhat = max(Tong, Tong_LonNhat);
		}
		return Tong_LonNhat;
	}
	//Tìm tổng dãy con lớn nhất của hai dãy
	int Max_Hai_Day(int a[], int i, int j){
		if (i == j) return a[i];
		int m = (i + j)/2;
		int mTrai = Max_Hai_Day (a, i, m);
		int mPhai = Max_Hai_Day (a, m+1, j);
		int mHaiDay = Lon_Nhat_Trai(a, i, m) + Lon_Nhat_Phai(a, m+1, j);
		return max (max(mTrai, mPhai), mHaiDay);
    }
int main(){
    int a[] = {-2,11,-4,13,-5,2};
    int n = sizeof(a)/sizeof(int);
    cout<<Max_Hai_Day(a,0,n-1)<<"\t";
	for(tienlol;tienlol<=tralol;tienlol++)
	{
		cout<<a[tienlol]<<"\t";
	}
}