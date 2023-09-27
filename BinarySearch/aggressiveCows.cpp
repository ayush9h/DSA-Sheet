#include<bits/stdc++.h>
using namespace std;


bool canPlace(vector<int>&stalls,int k,int dist)
{
    int cowCount = 1;
    int lastPos = stalls[0];
    int n = stalls.size();
    
    for(int i = 1;i<n;i++)
    {
        if(stalls[i] - lastPos >= dist)
        {
            cowCount++;
            lastPos = stalls[i];
        }
        if(cowCount >= k) return true;
    }
    return false;
}

int AggressiveCows(vector<int>&stalls,int k)
{
    int n = stalls.size();
    
    int low = 0;int high = stalls[n-1] - stalls[0];
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(canPlace(stalls,k,mid))
        {
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n;
    cin>>n;
    vector<int> stalls(n,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>stalls[i];
    }
    
    int k;
    cin>>k;
    
    sort(stalls.begin(),stalls.end());
    
    cout<<AggressiveCows(stalls,k)<<endl;
    return 0;
}
