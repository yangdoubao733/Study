#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    float a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"The matrix is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.2f ",a[i][j]);
        }
        cout<<endl;
    }
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i][i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i][n-i-1];
    }
    float average = sum/(2*n);
    printf("The mean value is: %.2f\n", average);
    return 0;
}