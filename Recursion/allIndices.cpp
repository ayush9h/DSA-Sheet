#include<bits/stdc++.h>
using namespace std;
void allIndices(vector<int> &arr, int n, int  m,vector<int>&ans,int ind)
{
	if(ind == n)
	{
		return;
	}

	if(arr[ind]== m)
	{
		ans.push_back(ind);
	}

	allIndices(arr,n,m,ans,ind + 1);
}
int main() {
	int n;
	cin>>n;
	
	vector<int> arr(n,0);
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	int m;
	cin>>m;

	vector<int>ans;

	allIndices(arr,n,m,ans,0);

	for(int i = 0;i<ans.size();i++)
	{
		cout<<ans[i] << " ";
	}
	return 0;
}
