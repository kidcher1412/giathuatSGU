#include<iostream>
using namespace std;

int max (int a, int b) {
		if (a > b) return a;
		return b;
		}
//Duyet qua tat ca cac day con
int dcln(int a[],int n){
    int tongl=INT32_MIN;
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=a[j];
            tongl = max(tongl,sum);
        }
    }
    return tongl;
}  
int maxQHD(int a[],int n)
{
	int maxts = a[0];
	int tong=a[0];
	for(int i=1;i<n;i++)
	{
		tong = max(tong+a[i],a[i]);
		maxts= max(tong,maxts);
	}
	return maxts;	
}
// Chia de tri
	//Tìm tổng dãy con lớn nhất bên trái
	int Lon_Nhat_Trai (int a[], int i, int j)
	{
		int Tong_LonNhat = INT32_MIN;
		int Tong = 0;
		for (int v = j; v >= i; v--){
			Tong = Tong + a[v];
			Tong_LonNhat = max(Tong, Tong_LonNhat);
		}
		return Tong_LonNhat;
	}
	//Tìm tổng dãy con lớn nhất bên phải
	int Lon_Nhat_Phai (int a[], int i, int j){
		int Tong_LonNhat = INT32_MIN;
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
	//Tìm tổng dãy con lớn nhất của dãy đầu vào
	int MaxTS_CDT (int a[], int N) {
		cout<<"\nChia de tri\n";
		return Max_Hai_Day (a, 0, N-1);
	}
int main(){
	cout<<" ----------- Tim day con co trong so lon nhat -------------------\n";
    int a[11] = {-4,-5,12,5,4,-5,8,-12,8,10,-2};
    // cout<<"\n"<<dcln(a, 11);
    // cout<<MaxTS_CDT(a,11);
	cout<<maxQHD(a,sizeof(a)/sizeof(int));
}









