#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c,s,t,p;
    scanf("%f %f %f",&a,&b,&c);
    if (a<b){ //进行排序
        t=a;
        a=b;
        b=t;
    }
    if(b<c){
        t=b;
        b=c;
        c=t;
    }
    if(a<b){
        t=a;
        a=b;
        b=t;
    }
    if(a < b+c){ //判断是不是三角形
        p=(a+b+c)/2.0;
        s=sqrt(p*(p-a)*(p-b)*(p-c)); //算面积
        if(a==b && b==c)
        { //是等边
            printf("This is an equilateral triangle.\n");
        }
        else if (a*a == b*b+c*c)
        { //是直角
            printf("This is a right triangle.\n");
        }
        else if (a == b || b == c || c == a)
        { //是等腰
            printf("This is an isosceles triangle.\n");
        }
        else{ //普通三角形
            printf("This is a general triangle.\n");
        }
        printf("The area of this triangle is %.2f.",s);
        
    }
    else{ //不是三角
        printf("can not form a triangle.\n");
    }
    return 0;
}
