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
    
    int largest = arr[0];
    int secondlargest = -1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] > largest)
        {
            secondlargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>secondlargest && arr[i]<largest)
        {
            secondlargest = arr[i];
        }
    }
    
    cout<<"SecondLargest Element is: "<<secondlargest<<endl;
    return 0;
}
