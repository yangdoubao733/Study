#include<stdio.h>


int sum (int *array, int n)
{ int i, s = 0;
for(i=0; i<n; i++)
s += array[i]; 
return(s);
}


int main(void )
{ int i;
int b[5] = {1, 4, 5, 7, 9};
printf("%d\n", sum(b, 1));
return 0;
}