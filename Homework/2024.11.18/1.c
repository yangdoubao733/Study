#include<stdio.h>

void sum_diff(float op1,float op2,float *psum,float *pdiff)

{
    *psum = op1+op2;
    *pdiff = op1-op2;
    printf("the sum is %.6f\nthe diff is %.6f",*psum,*pdiff);
}

int main(void)

{
    float op1,op2,op3,op4,*psum,*pdiff;
    scanf("%f %f",&op1,&op2);
    psum = &op3;
    pdiff = &op4;
    sum_diff(op1,op2,psum,pdiff);
}

