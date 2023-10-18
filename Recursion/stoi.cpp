#include<bits/stdc++.h>
using namespace std;
int stringtoInteger(string s,int len)
{
	if(len==0)
	{
		return 0;
	}

	int lastInteger = s[len - 1] - '0';

	int remdigits = stringtoInteger(s,len- 1);

	return remdigits*10 + lastInteger;
}
int main() {
	string s;
	cin>>s;

	int len = s.length();

	int result = stringtoInteger(s,len);

	cout<<result<<endl;
	return 0;
}
