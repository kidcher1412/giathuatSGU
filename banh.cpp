#include<iostream>
using namespace std;
int check(double mid, int f, int r[], int n){
	int sum=0;
	for(int i=0; i<n; i++){
		sum += int((3.14*r[i]*r[i])/mid);
		if(sum>=f)return 1;
	}
	return 0;
}
double cat(int r[], int n, int f){
	double mid, low=0, hight =0;
	for(int i=0; i<n; i++){
		hight += (3.14*r[i]*r[i]);
	}
	hight=hight/f;
	if(check(hight,f,r,n)==1){
		return hight;
	}else{
		while((hight-low)>0.0001){
			mid=(hight+low)/2;
		//cout<<mid<<endl;
			if(check(mid,f,r,n)==1){
				low=mid;
			}else hight=mid;
		}
		return hight;
	}}
int main(){
	int n,f;
	cin>>n>>f;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}	cout<<cat(a,n,f);
}
