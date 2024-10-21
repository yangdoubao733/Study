#include<stdio.h>
#include<math.h>

int main(){
    int n,temp;
    scanf("%d",&n);
    float a[n][2];
    float x0,y0,tan;
    double r[n][2];
    for(int i=0;i<n;i++){
        scanf("%f %f",&a[i][0],&a[i][1]);
    }
    scanf("%f %f",&x0,&y0);
    for(int i=0;i<n;i++){
        tan = atan((a[i][1]-y0)/(a[i][0]-x0));
        if(a[i][0] > x0 && a[i][1] > y0){ //第一象限

        }
        else if(a[i][0] < x0 && a[i][1] > y0){ //第二象限
            tan += 3.14;
        }
        else if(a[i][0] < x0 && a[i][1] < y0){ //第三象限
            tan += 3.14;
        }
        else if(a[i][0] > x0 && a[i][1] < y0){ //第四象限
            tan += 6.28;
        }
        else if(a[i][0] > x0 && a[i][1] == y0){ //正x轴
            tan = 0;
        }
        else if(a[i][0] == x0 && a[i][1] > y0){ //正y轴
            tan = 3.14/2;
        }
        else if(a[i][0] < x0 && a[i][1] == y0){ //负x轴
            tan = 3.14;
        }
        else if(a[i][0] == x0 && a[i][1] < y0){ //负y轴
            tan = 3.14/2*3;
        }
        else if(a[i][0] == x0 && a[i][1] == y0){ //原点
            tan = -1;
        }
        r[i][0] = tan;
        r[i][1] = i;

    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(r[j][0] > r[j+1][0]){
                temp = r[j][0];
                r[j][0] = r[j+1][0];
                r[j+1][0] = temp;
                temp = r[j][1];
                r[j][1] = r[j+1][1];
                r[j+1][1] = temp;

            }
        }
    }
    printf("The counterclockwise arrangement of the %d-gon is:",n);
    for(int i=0;i<n;i++){
        temp = r[i][1];
        printf(" (%.2f, %.2f)",a[temp][0],a[temp][1]);
    }
    return 0;
}