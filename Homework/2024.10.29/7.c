#include<stdio.h>
//以下为全局变量
int price[5]={100,50,35,150,200};//产品报价
int item_n[100][5];//用来表示不同销售员对应产品销售数量的数组，如 item_n[1][3]表示销售员1销售的3号产品的数量。销售员编号从0开始
float sale[100];//用来存储没人的销售额 
int n=0;
void total_sales()
{
    /*
        计算每个销售人员的总销售额并输出。
        销售佣金为10％，请计算每个销售员的收入并输出 
        调用 maximum() 输出谁是销售冠军 
    */
    for(int i=0;i<n;i++){
        sale[i] = item_n[i][0]*price[0]+item_n[i][1]*price[1]+item_n[i][2]*price[2]+item_n[i][3]*price[3]+item_n[i][4]*price[4];
        printf("total sales of salesman %d is %.0f\n",i,sale[i]);
        printf("income of salesman %d is %.4f\n",i,sale[i]/10);
    }   
}
int maximum ()
{
     //找出谁是销售冠军,返回为数组最大值的索引
    int target = 0;
    float max = sale[0];
    for(int i=1;i<n;i++){
        if(sale[i] > max){
            max = sale[i];
            target = i;
        }
    } 
    return target;
	
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d %d",&item_n[i][0],&item_n[i][1],&item_n[i][2],&item_n[i][3],&item_n[i][4]);
    }
    
    total_sales();
    printf("sales-champion is salesman %d",maximum());
} 
