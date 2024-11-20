#include<stdio.h>

void maxmin(int *p){
    int *max = p,*min = p;
    int temp1,temp2,temp3,temp4;
    for(int *i=p;i<p+10;i++){
        if(*i <= *min)min = i;
        if(*i >= *max)max = i;
    }
    temp1 = *min;
    temp2 = *max;
    temp3 = *p;
    temp4 = *(p+9);
    *p = temp1;
    *min = temp3;
    *(p+9) = temp2;
    *max = temp4;

}

int main(){
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    maxmin(a);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}