#include <stdio.h>

int main() {
    int a=100;
    while(a<=999){
        if(((a/100)*(a/100)*(a/100)+(a%10)*(a%10)*(a%10)+((a-a/100*100-a%10)/10)*((a-a/100*100-a%10)/10)*((a-a/100*100-a%10))/10) == a){
            printf("%d\n",a);
        }
        a+=1;
    }
    return 0;
}
