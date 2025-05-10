#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=a[0];
    int max_p;
    for(int i=1;i<n;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            max_p = i;
        }
    }
    int target = 1;
    for(int i=0;i<n;i++)
    {
        if(max < a[i]*2 && i != max_p)
        {
            target = 0;
        }
    }
    cout<<max<<" "<<max_p<<" ";
    if(target == 1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}