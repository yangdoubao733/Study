#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){
    char input[50];
    int len,i=0,isNegative=0,declen=0;
    float result=0,dec=0;
    gets(input);
    len=strlen(input);
    if(input[0] == '-'){
        isNegative=1;
        i+=1;
    }
    while(i<len){
        if(input[i] == '.'){
            i++;
            break;
        }    
        result *= 10;
        result += input[i]-48;
        i++;
    }
    while(i<len){

        dec *= 10;
        dec += input[i]-48;
        i++;
        declen++;
    }
    dec *= pow(0.1,declen);
    result += dec;
    if(isNegative == 1)result *= -1;
    printf("%.4f \n",result);
    return 0;
}