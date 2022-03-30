#include"iostream"
using namespace std;
int A[] = {3,-2,11,-4,13,-5,2,7};
long maxLeft(int i, int j)
{
    long maxL= A[j];
    int s = 0;
    for (int k = j; k >= i ; k--)
    {
        s += A[k];

        // if (maxL<s)
        // {
        //         maxL = s;
        // }
    }   
    return s;
}
long maxRight(int i,int j)
{
    long maxR = A[i];
    int s = 0;
    for (int  k = i; k <=j ; k++)
    {
        s+=A[k];
        
        // if (maxR<s)     
        // {
        //     maxR=s;
        // }       
    }
    return s;
    
}
long maxSeq(int i, int j)
{
    if(i==j) return A[i];
    int m = (i+j)/2;
    long ml = maxSeq(i,m);
    long mr = maxSeq(m+1,j);
    long MaxL = maxLeft(i,m);
    long MaxR = maxRight(m+1,j);
    long max ;
    long MaxLR = MaxL+MaxR;
    // return max(max(ml,mr),MaxLR);
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
   	cout<<"Max Seq :"<< maxSeq(0,n-1);
   	Prinft_Seq(A,n);
  return 0;
}
