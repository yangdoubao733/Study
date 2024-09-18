#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c;
    float x1,x2;
    scanf("%f %f %f",&a,&b,&c);
    if(a == 0){ //a等于0
        printf("This equation is not a quadratic equation.\n");
        x1 = -(c/b);
        printf("The root of the equation is %.2f.",x1);
    }
    else{ //a不等于0
        if(b*b-4*a*c == 0){ //delta等于0
            printf("This equation has two equal real roots.\n");
            x1 = -b/(a*2);
            printf("The root of the equation is %.2f.",x1);
        }
        else if (b*b-4*a*c > 0) //delta大于0
        {
            printf("This equation has two unequal real roots.\n");
            x1= (-b+sqrt(b*b-4*a*c))/(a*2);
            x2= (-b-sqrt(b*b-4*a*c))/(a*2);
            printf("The roots of the equation are %.2f and %.2f.",x1,x2);
        }
        else{
            printf("This equation has two conjugate complex roots.\n");
            x1 = -b/(a*2);
            x2 = sqrt(-(b*b-4*a*c))/(a*2);
            printf("The roots of the equation are %.2f+-i%.2f.",x1,x2);
        }
    }
    return 0;
}