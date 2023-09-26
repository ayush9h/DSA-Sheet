#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int totalSum = (n * (n+1)) / 2;
    
    int s2 = 0;
    for(int i = 0;i<n - 1;i++)
    {
        s2+=arr[i];
    }
    cout<<"Missing Number: "<<totalSum - s2;
    return 0;
}
