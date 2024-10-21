#include<stdio.h>
#include<math.h>

int main(){
    int n;
    float x0,y0;
    double a,b,c,p,s=0;
    scanf("%d",&n);
    float tu[n][2];
    for(int i=0;i<n;i++){
        scanf("%f %f",&tu[i][0],&tu[i][1]);
    }
    scanf("%f %f",&x0,&y0);
    for(int i=1;i<n-1;i++){
        a = sqrt((tu[i][0]-x0)*(tu[i][0]-x0) + (tu[i][1]-y0)*(tu[i][1]-y0));
        b = sqrt((tu[i][0]-tu[i+1][0])*(tu[i][0]-tu[i+1][0]) + (tu[i][1]-tu[i+1][1])*(tu[i][1]-tu[i+1][1]));
        c = sqrt((tu[i+1][0]-x0)*(tu[i+1][0]-x0) + (tu[i+1][1]-y0)*(tu[i+1][1]-y0));
        p = (a+b+c)/2;
        s += sqrt(p*(p-a)*(p-b)*(p-c));
    }
    printf("The area of %d-gon is: %.2f",n,s);
    return 0;
}