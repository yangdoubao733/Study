#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    int kongge;
    int xinghao;
    for(int n=1;n<=a*2-1;n++){//n为第几行
        if(n<=a){//上半部分
            xinghao = 2*n-1;
            kongge = (a*2-1-xinghao)/2;
        }
        else{//下半部分
            int n2=a*2-n;

            xinghao = 2*n2-1;
            kongge = (a*2-1-xinghao)/2;
        }
        for(int n1=1;n1<=kongge;n1++){
            printf(" ");
        }
        for(int n1=1;n1<=xinghao;n1++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}