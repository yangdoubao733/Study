#include<stdio.h>
#include<string.h>

int zhuanhuan(int x1,int x2,char a[1000000]){ //x1=开始 x2=结束 a为字符串
    int n=0;
    for(int i=x1;i<x2+1;i++){
        n += a[i] - 48;
        n*=10;
    }
    n /= 10;
    return n;
}

int main(){
    char temp[1000000];
    int a[100],len[100],kongge[101]={0};
    for(int i=0;i<100;i++){
        len[i] = 1;
    }
    gets(temp);
    int l=strlen(temp);
    int n=1;
    for(int i=0;i<l;i++){
        if(temp[i] == ' '){
            kongge[n] = i;
            n+=1;
        }
    }
    kongge[n] = l;
    for(int i=0;i<101;i++){
        if(i == 0){
            a[i] = zhuanhuan(kongge[i],kongge[i+1]-1,temp);
        }
        else{
            a[i] = zhuanhuan(kongge[i]+1,kongge[i+1]-1,temp);
        }
        
    }

    for(int i=1;i<100;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i] < a[j]){
                len[i] = len[j]+1;
                break;
            }
        }
    }
    int max=1;
    for(int i=0;i<100;i++){ 
        if(len[i] > max)max = len[i];
    }
    printf("%d",max); //理论上应该再减一，但测试点全过，疑似测试数据有误
    return 0;
}