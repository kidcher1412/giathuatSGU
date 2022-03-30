#include<iostream>
using namespace std;

int max (int a, int b) {
		if (a > b) return a;
		return b;
		}
//Vét cạn
void MaxTS(int a[], int n){
	cout<<"Vet can---\n";
    int tongL = INT32_MIN;
    int tong = 0;
	int f=0, l=0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++){
            tong = 0;
            for (int k = i; k <= j; k++) {
                tong = tong + a[k];
            }
            // tongL = max(tong, tongL);
			if (tong>tongL)
        	{
				tongL = tong;
				f = i;  
				l = j; 
        	}
        }
    }
	cout<<"Mang con co trong so "<<tongL<<" la lon nhat:"<<"\n";
	for(int g=f;g<=l;g++){
		cout<<a[g]<<"\t";
	}
}

void MaxTS2 (int a[], int N) {
	cout<<"VVVVVVVVVVVVVVvv---\n";
	int f=0, l=0;
    int maxsum = INT32_MIN; //âm vô cùng
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = i; j < N; j++) {
            sum = sum + a[j];
            // maxsum = max (sum, maxsum);
			if (sum>maxsum)
        	{
				maxsum = sum;
				f = i; 
				l = j; 
        	}
        }
    }
	cout<<"Mang con co trong so "<<maxsum<<" la lon nhat:"<<"\n";
	for(int g=f;g<=l;g++){
		cout<<a[g]<<"\t";
	}
}    

//---------------------------------------------------------
// Chia de tri
	//Tìm tổng dãy con lớn nhất bên trái
	int cdt_f=0;
	int cdt_l=0;
	int Lon_Nhat_Trai (int a[], int i, int j)
	{
		int Tong_LonNhat = 0;
		int Tong = 0;
		for (int v = j; v >= i; v--){
			Tong = Tong + a[v];
			if (Tong_LonNhat <Tong) cdt_f = v;
			Tong_LonNhat = max(Tong, Tong_LonNhat);
			
		}
		return Tong_LonNhat;
	}
	//Tìm tổng dãy con lớn nhất bên phải
	int Lon_Nhat_Phai (int a[], int i, int j){
		int Tong_LonNhat = 0;
		int Tong = 0;
		for (int v = i; v <= j; v++){
			Tong = Tong + a[v];
			if (Tong_LonNhat <Tong) cdt_l = v;
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
	void MaxTS_CDT1(int a[], int N) {
		cout<<"\nChia de tri---";
		cout<<"\nMang con co trong so "<<Max_Hai_Day (a, 0, N-1)<<" la lon nhat: \n";
		for(cdt_f;cdt_f<=cdt_l;cdt_f++){
			cout<<a[cdt_f]<<"\t";
		}
	}
//---------------------------------------------------------------------------------
// Quy hoach dong
void MaxTS_QHD (int a[], int N) {
	cout<<"\nQuy hoach dong---\n";
	int f=0, l=0;
    int maxsum = a[0];
    int sum = a[0];
    for (int i = 1; i < N; i++) {
        sum = max(a[i], sum + a[i]);
		// cout<<sum<<"\t";
        if(sum>maxsum){
			maxsum = sum;
			l=i;
		}
    }
	int t=maxsum;
	int k = l;
	cout<<"Mang tong: ";
	for (k; k>=0; k--)
	{
		t=t-a[k];
		cout<<t<<"\t";
		if(t==0) {
			f=k;
			break;
			}
	}
	cout<<"\nMang con co trong so "<<maxsum<<" la lon nhat: \n";
	for(f;f<=l;f++){
		cout<<a[f]<<"\t";
	}
}
// void MaxTS_QHD2 (int a[], int n) {
// 	cout<<"\nQuy hoach dong\n";
// 	int f=0, l=0;
//     int maxsum = INT32_MIN;
// 	int s[100];
// 	s[0] = 0;
// 	for (int i = 1; i <=n; i++)
// 	{
// 		s[i] = s[i-1] + a[i];
// 		// cout<<s[i]<<"\t";
// 	}
// 	for (int i = 1; i < n-1; i++)
// 	{
// 		for (int j = i+1; j < n; j++)
// 		{
// 			if(maxsum < s[j]-s[i])
// 			{
// 				maxsum = s[j]-s[i];
// 				f = i+1;
// 				l = j;
// 			}
// 		}
// 	}
// 	// cout<<maxsum;
// 	cout<<"\nMang con co trong so "<<maxsum<<" la lon nhat: \n";
// 	for(f;f<=l;f++){
// 		cout<<a[f]<<"\t";
// 	}
// }
void TruyVet(int a[],int n, int max){
	int l, f;
	int maxt = max;
	for (int i = n-1; i >= 0 ; i--)
	{
		if(maxt ==0 ) f = i;
		if(maxt - a[i]<maxt && maxt - a[i]<max)
		{
			maxt = maxt - a[i];
			l = i;
			// break;
		}
	}
	for(f; f<=l; f++){
		cout<<"\t"<<a[f];
	}
	
}

void maxts_vc(int a[], int n){
	int f,l,sum;
	int max= INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		sum =0;
		for (int j = i; j < n; j++)
		{
			sum = sum+a[j];
			if(sum>max){
				max = sum;
				f=i;
				l=j;
			}
		}
		
	}
	cout<<"Mang con co trong so "<<max<<" la lon nhat: \n";
	for(f;f<=l;f++){
		cout<<a[f]<<"\t";
	}
	
}

int main(){
	cout<<" ----------- Tim day con co trong so lon nhat -------------------\n";
    int a[11] = {-4,-5,12,5,4,-5,8,-12,8,10,-2};
    MaxTS(a, 11);
    // cout<<"\n"<<MaxTS_CDT(a,11)<<"\n";
	MaxTS_CDT1(a,11);
    MaxTS_QHD(a,11);
	// TruyVet(a,11,MaxTS_CDT(a,11));
	cout<<"\n";
    return 1;
}
