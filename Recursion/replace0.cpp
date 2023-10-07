#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
	//base case
	if(n==0)
	{
		return 0;
	}

	int digit = n % 10;

	if(digit == 0)
	{
		digit = 5;
	}

	return solve(n/10)*10 + digit;
}
int main () {
	int n;
	cin>>n;

	int ans = solve(n);
	cout<<ans<<endl;
	return 0;
}
