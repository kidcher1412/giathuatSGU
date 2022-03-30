#include<stdio.h>
#include<math.h>
#define PI acos(-1)
double v[10010];
 
 
int main(){
	int n,f,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&f);
		int i,r;
		double right=0.0,left=0.0,mid;
		for(i=0;i<n;i++){
			scanf("%d",&r);
			v[i]=PI*r*r;
			right+=v[i];
		}
		f+=1;
		right/=f;
		while(right-left>1e-7){
			int sum=0;
			mid=(right+left)/2.0;
			for(i=0;i<n;i++){
				sum+=(int)(v[i]/mid);
			}
			if(sum>=f) left=mid;
			else right=mid;
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}

