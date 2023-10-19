#include<bits/stdc++.h>
using namespace std;
void generateBinaryStrings(string &s,vector<string> &ans,string output,int ind)
{
	if(ind >= s.length())
	{
		ans.push_back(output);
		return;
	}

	if(s[ind] == '?')
	{
		generateBinaryStrings(s,ans,output + '0',ind + 1);
		generateBinaryStrings(s,ans,output + '1',ind + 1);
	}
	else{
		generateBinaryStrings(s,ans,output + s[ind],ind + 1);
	}
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;

		vector<string>ans;
		string output;

		generateBinaryStrings(s,ans,output,0);

		for(int i = 0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
