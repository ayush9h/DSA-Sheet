#include<bits/stdc++.h>
using namespace std;
void evenRecursion(int ind,int n)
{
	if(n<=0) return;

	if(ind>n) return;

	if(ind%2==0)
	{
		cout<<ind<<endl;
	}
	evenRecursion(ind+1,n);
}
void oddRecursion(int n)
{
	if(n<=0) return;

	if(n%2!=0)
	{
		cout<<n<<endl;
		
	}
	oddRecursion(n-1);
}
int main() {
	int n;
	cin>>n;

	oddRecursion(n);
	
	int ind = 1;
	evenRecursion(ind,n);
	return 0;
}
