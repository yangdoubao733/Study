#include<iostream>
using namespace std;
int main() 
{
    int a[15];
    for(int i=0;i<15;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<15;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int s;
    cin>>s;
    for(int i=0;i<15;i++)
    {
        if(a[i]==s)
        {
            cout<<"the index of "<<s<<" is "<<i<<endl;
            break;
        }
    }
    for(int i=0;i<15;i++)
    {
        for(int j=i+1;j<15;j++)
        {
            if(a[i] == a[j])
            {
                cout<<"the same height is "<<a[i]<<", and the indices are: "<<i<<","<<j<<endl;
            }

        }
    }
    return 0;
}