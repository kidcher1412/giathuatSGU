#include"iostream"


using namespace std;

int A[] = {-2,11,-4,13,-5,2};

long maxLeft(int i, int j,int Seq[])
{
    long maxL= A[j];
    int s = 0;
    cout<<"Left :\t";
    for (int k = j; k >= i ; k--)
    {
        cout<<"A["<<k<<"] : "<<A[k]<<"\t";
        s += A[k];
        Seq[k] = s;
        if (maxL>s)
        {
                s = maxL;
                
        }
        
    }
    cout<<"\n";
    
    return s;

}
long maxRight(int i,int j,int Seq[])
{
        cout<<"Right: \t";
    long maxR = A[i];
    int s = 0;

    for (int  k = i; k <=j ; k++)
    {
         cout<<"A["<<k<<"] : "<<A[k]<<"\t";
        s+=A[k];
        
        Seq[k] = s;
        if (maxR>s)     
        {
            s = maxR;
        }
        
    }
    cout<<"\n";

    return s;
    
}
long maxSeq(int i, int j,int Seq[])
{
    if(i==j) return A[i];
    int m = (i+j)/2;
    long ml = maxSeq(i,m,Seq);
    long mr = maxSeq(m+1,j,Seq);
    long MaxL = maxLeft(i,m,Seq);
    long MaxR = maxRight(m+1,j,Seq);

    long max ;
    long MaxLR = MaxL+MaxR;

    if (ml > mr)
    {
        max = ml;
    }else
    {
        max = mr;
    }
    if (max < MaxLR)
    {
        max = MaxLR;
    }
    
    return max;

}
void Prinft_Seq(int Seq[],int n)
{
	cout<<endl;
	for(int i =0 ; i < n ; i ++ )
	cout<<Seq[i]<<"\t";
}
int main(int argc, char const *argv[])
{
    int n = sizeof(A)/sizeof(A[0]);

	int Seq[n];
	cout<<"/n/n--------------------------/n";

   cout<<"Max Seq :"<< maxSeq(0,n-1,Seq);
   	Prinft_Seq(A,n);
   Prinft_Seq(Seq,n);
    return 0;
}
