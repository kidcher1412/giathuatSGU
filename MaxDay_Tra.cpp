#include"iostream"
using namespace std;

void TongDayCon(int A[],int S[],int n,int &Max){
	
    S[0] = A[0];
     Max = S[0];
    for (int i = 1; i < n; i++)
    {
        if (S[i-1]<0)
        {
            S[i] = A[i];
        }
        else if (S[i-1]>=0)
        {
            S[i] = S[i-1] + A[i];
        }
        if(Max<S[i])
        	Max = S[i];
    }    
}
void PrintArr(int S[],int n)
{
		for (int i = 0; i < n; i++)
    {
        cout<<S[i]<<"\t";

    }
}
int main(int argc, char const *argv[])
{
    int A[] = {-2,11,-4,13,-5,2};
    int Max;
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Mang da cho : \n";
    PrintArr(A,n);
    int *S = new int[n];
    TongDayCon(A,S,n,Max);
    cout<<"\nTong day con sau khi tinh : \n";
    PrintArr(S,n);
    cout<<"Max Seq: "<<Max;
    return 0;
}
