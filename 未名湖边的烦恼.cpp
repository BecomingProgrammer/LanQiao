#include<stdio.h>  
int fun(int m,int n)  
{  
    if(m<n)  
        return 0;  
    if(n==0)  
        return 1;  
    return fun(m-1,n)+fun(m,n-1);  
}  
int main()  
{  
    int m,n;  
    scanf("%d%d",&m,&n);  
    printf("%d\n",fun(m,n));  
    return 0;  
}  
