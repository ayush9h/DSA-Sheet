#include<bits/stdc++.h>
using namespace std;

int canallocate(vector<int> &arr,int pagesallocated)
{
    int n = arr.size();
    int students = 1;
    int pagesperstudent = 0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] + pagesperstudent <= pagesallocated)
        {
            pagesperstudent+=arr[i];
        }
        else{
            students++;
            pagesperstudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>&arr,int n,int m)
{
    //base case
    if(m>n) return -1;
    
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    
    while(low <= high)
    {
        int mid = (low+high)/2;
        int students = canallocate(arr,mid);
        
        if(students > m)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
