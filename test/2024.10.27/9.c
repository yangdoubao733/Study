#include<stdio.h>
#include<math.h>

double distance(double x1,double y1,double x2,double y2){
    double d=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return d;
}
int main(){
    int n;
    double x1,y1,x2,y2,r1,r2,min1,min2,max1,max2;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    scanf("%d",&n);
    double xy[n][3];
    double d1[n],d2[n];
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&xy[i][0],&xy[i][1]); //输入导弹坐标
    }
    for(int i=0;i<n;i++){
        d1[i] = distance(x1,y1,xy[i][0],xy[i][1]);
        d2[i] = distance(x2,y2,xy[i][0],xy[i][1]);  //求每个防空炮到各个导弹的距离
    }
    max1 = d1[0];
    max2 = d2[0];
    for(int i=1;i<n;i++){
        if(d1[i] > max1)max1 = d1[i];
        if(d2[i] > max2)max2 = d2[i];
    }
    for(int i=0;i<n;i++){
        xy[i][2] = 0;
    }
    r1 = max1; //从半径最大开始遍历
    r2 = max2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int a=0;a<n;a++){
                if(d1[i] >= d1[a])xy[a][2] = 1; //判断导弹是否被拦截
                if(d2[j] >= d2[a])xy[a][2] = 1;
            }
            int target = 1;
            for(int a=0;a<n;a++){
                if(xy[a][2] == 0)target = 0; //判断是否全部拦截
            }
            if(target == 1 && (pow(d1[i],2)+pow(d2[j],2)) < pow(r1,2)+pow(r2,2)){ //全部拦截且代价更小，则更新代价半径
                r1 = d1[i];
                r2 = d2[j];
            }
            for(int a=0;a<n;a++){ //重置导弹状态
                xy[a][2] = 0;
            }
        }
    }
    printf("%.0lf",pow(r1,2)+pow(r2,2));
    return 0;
}
//0 0 6 0 5 -4 -2 -2 3 4 0 6 -2 9 1