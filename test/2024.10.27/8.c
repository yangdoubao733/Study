#include<stdio.h>
#include<math.h>

double distance(double x1,double y1,double x2,double y2){
    double d=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return d;
}
int main(){
    int n;
    double x1,y1;
    double max;
    scanf("%lf %lf",&x1,&y1);
    scanf("%d",&n);
    double xy[n][2];
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&xy[i][0],&xy[i][1]);
    }
    max = distance(x1,y1,xy[0][0],xy[0][1]);
    for(int i=1;i<n;i++){
        if(distance(x1,y1,xy[i][0],xy[i][1]) > max)max = distance(x1,y1,xy[i][0],xy[i][1]);
    }
    printf("%.2lf",max);
    return 0;
}