#include<stdio.h>

int isPrime(long x){
    int target = 1;
    for(long i=2;i<x;i++){
        if(x%i == 0)target = 0;
    }
    return target;
}

void getPrimePair(long m){
    int target = 0;
    for(long i=2;i<=m/2;i++){
        long j = m-i;
        if(isPrime(i) && isPrime(j)){
            printf("%ld = %ld + %ld\n",m,i,j);
            target += 1;
        }
        
    }
    printf("The number %ld has %d prime number decomposition methods",m,target);
}
int main(){
    long m;
    scanf("%ld",&m);
    if(m>=4 && m%2 == 0){
        getPrimePair(m);
    }
    else{
        printf("The end");
    }
    return 0;
}