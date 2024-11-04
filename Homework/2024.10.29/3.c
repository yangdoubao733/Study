#include<stdio.h>
#include<math.h>

int n=-1;
int r=0;
int transform(int a){
    n+=1;
    int temp = a%2;
    a /= 2;
    r += (temp*pow(10,n));
    if(a == 0){
        return 0;
    }
    
    transform(a);
}

int main(){
    int a;
    scanf("%d",&a);
    transform(a);
    printf("%d",r);
}

