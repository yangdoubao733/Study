#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct{
   char *ch;       //若串非空,则按串长分配存储区,
                   //否则ch为NULL
   int  length;    //串长度
}HString;

typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitString(HString &T) {
	T.length=0;
	T.ch=NULL;
	return OK;
}


Status ClearString(HString &S){
//将S清为空串
	if(S.ch) {
		free(S.ch); 
	}
	S.ch = NULL;
	S.length=0;
	return OK;
}//ClearString

Status StrAssign(HString &T,char *chars){

    int i=0;
	T.ch = (char*)malloc((strlen(chars) + 1) * sizeof(char));
	if (T.ch == NULL) {
		return ERROR; // Handle memory allocation failure
	}
	while(chars[i]){
		T.ch[i] = chars[i];
		i++;
	}
    T.ch[i] = '\0';
    T.length = i;
    return OK;

}//StrAssign    



int StrLength(HString S){
//返回S的元素个数,称为串的长度
	return S.length;
}//StrLength


int StrCompare(HString S,HString T){
//若S=T,返回值=0;若S≠T,返回值=1

    if(S.length == T.length){
        for(int i=0;i<S.length;i++){
            if(S.ch[i] != T.ch[i])return 1;
        }
        return 0;
    }
    else return 1;

}//StrCompare    

Status StrInsert(HString &S,int pos,HString T){

    if(pos<0 || pos > S.length+1) return ERROR;
    char* temp;
    temp = (char*)malloc((strlen(S.ch)+strlen(T.ch)+1)*sizeof(char));
    if (temp == NULL) return ERROR;  // 内存分配失败检查
    for(int i=0;i<pos-1;i++){
        temp[i] = S.ch[i];
    }
    int j=0;
    for(int i=pos-1;i<pos+T.length-1;i++){
        temp[i] = T.ch[j++];
    }
    for(int i=pos-1;i<S.length;i++){
        temp[i+T.length] = S.ch[i];
    }
    temp[S.length+T.length] = '\0';
    if(S.ch)free(S.ch);
    S.ch = temp;
    S.length = S.length + T.length;
    return OK;

}//StringInsert    


void StrTravel(HString S)
{
	int i;
	for(i=0;i<S.length;i++)
	{
		printf("%c",S.ch[i]);
	}
	printf("\n");
}
int main()
{
	HString S1,S2,S3;
	InitString(S1);//初始化串1
	InitString(S2);//初始化串2
	InitString(S3);//初始化串3
	char str1[100],str2[100],str3[100];
	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",str3);
	StrAssign(S1,str1);//串1赋值
	StrAssign(S2,str2);//串2赋值
	StrAssign(S3,str3);//串3赋值
	int pos;
	scanf("%d",&pos);

	StrTravel(S1);
	StrTravel(S2);
	StrTravel(S3);
	if(StrInsert(S1,pos,S2)==OK)//串插入
	{
		StrTravel(S1);//串打印输出
	}
	else
	{
		printf("insert fail\n");
	}
	int cmp = StrCompare(S1,S3);
	if(cmp == 0)
		printf("equal\n");
	else
		printf("not equal\n");
	ClearString(S1);
	ClearString(S2);
	ClearString(S3);
	return 0;
}