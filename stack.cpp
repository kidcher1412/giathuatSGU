#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	stack<int> s;
	cout<<"nhap so vao di: "; cin>>n;
	for(int i=0;i<n;i++)
		{
			cout<<"nhap so thu "<<i<<" di:";
			int a; cin>>a;
			 s.push(a);
		}
	cout<<"============================"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<" so thu "<<i<<" : ";
			cout<<s.top();
			s.pop();
			cout<<endl;
		}
	
	return 0;
}
